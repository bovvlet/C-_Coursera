#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Date {
public:
    Date () {}
    /*
    * конструктор проверяющий границы чисел
    */
    Date (int year, int month, int day) {
        check_borders(year, month, day);
        this->year = year, this->month = month, this->day = day;    
    }
    /*
    * конструктор-парсер из строки в класс Date
    * проверяет правильность ввода и в случае
    * правильного ввода проверяет границы чисел
    */
    Date (const string& s) {
        stringstream ss(s);
        char sep;
        int year, month, day;
        
        if (!(ss >> year)) throw domain_error("");
        
        sep = '+';
        if (!(ss >> sep) or sep != '-') throw domain_error("");
        
        if (!(ss >> month)) throw domain_error("");

        sep = '+';
        if (!(ss >> sep) or sep != '-') throw domain_error("");

        if (!(ss >> day)) throw domain_error("");

        if (ss.peek() != -1) throw domain_error("");

        check_borders(year, month, day);
        this->year = year, this->month = month, this->day = day;   
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
    /*
    * возвращает класс Date в виде строки 
    */
    string GetStr() const {
        stringstream ss;
        ss << setfill('0')
        << setw(4) << year << '-'
        << setw(2) << month << '-'
        << setw(2) << day;
        return ss.str();
    }
private:
    int year = 1;
    int month = 1;
    int day = 1;
    /*
    * функция которую вызываются для проверки границ
    * в случае неправильных границ выдаёт исключение
    */
    void check_borders(int year, int month, int day) {
        if (month < 1 or month > 12)
            throw invalid_argument("Month value is invalid: " + to_string(month));
        if (day < 1 or day > 31)
            throw invalid_argument("Day value is invalid: " + to_string(day));
    }
};

/*
* сравнение сделанно при помощи векторов такая же
* идея как и лексикографическое сравнение строк
*/
bool operator < (const Date & lhs, const Date & rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

class Database {
public:
	void AddEvent(const Date & date, const string & event) {
        events[date].insert(event);
    }
	bool DeleteEvent(const Date & date, const string & event) {
        if (events.count(date) != 0 and events[date].count(event) != 0) {
            events[date].erase(event);
            
            if (events[date].empty())
                events.erase(date);
            
            return true;
        }
        return false;
    }
	int DeleteDate(const Date & date) {
        if (events.count(date) != 0) {
            int res = events[date].size();
            events.erase(date);
            return res;
        }
        return 0;
    }

	vector<string> Find(const Date & date) const {
        if (events.count(date) == 0)
            return {};
        vector<string> res;
        for (const string& e: events.at(date)) 
            res.push_back(e);
        return res;
    }

	void Print() const {
        for (const auto& pr: events) {
            string str_date = pr.first.GetStr();
            for (const string& e: pr.second)
                cout << str_date << " " << e << endl;
        }
    }
private:
    map<Date, set<string>>events;
};

/*
* функция использует конструктор-парсер чтобы
* перевести строку в класс Date, при этом
* функция ловит исключения и выводит сответвующий
* им текст, в случае исключения останавливает программу
*/
void make_date (Date& _date, const string& date) {
    try {
        _date = Date(date);
    } catch (const domain_error& de) {
        cout << "Wrong date format: " << date << endl;
        exit(0);
    } catch (const invalid_argument& ia) {
        cout << ia.what() << endl;
        exit(0);
    }
}

int main() 
{
	Database db;
    string command;
	while (getline(cin, command)) 
	{
		stringstream ss;
        ss << command;
        
        if (ss.str() == "")
            continue;
        
        string op;
        ss >> op;

        // чаще всего используемые переменные
        // будут случаи что они создадутся, но
        // не будут использованны. Сделанно чтобы
        // сократить количество повторений в коде
        Date _date;
        string date, event;
        ss >> date >> event;

        if (op == "Add") {
            make_date(_date, date);
            db.AddEvent(_date, event);
        } else if (op == "Del") {
            make_date(_date, date);

            if (event == "") {
                int N = db.DeleteDate(_date);
                cout << "Deleted " << N << " events" << endl;
            } else { 
                bool flag = db.DeleteEvent(_date, event);
                if (flag)
                    cout << "Deleted successfully" << endl;
                else 
                    cout << "Event not found" << endl;
            }
        } else if (op == "Find") {
            make_date(_date, date);
            vector<string>v = db.Find(_date);
            for (const string& e: v)
                cout << e << endl;
        } else if (op == "Print") {
            db.Print();
        } else {
            cout << "Unknown command: " << op << endl;
            return 0;
        }
	}
	return 0;
}