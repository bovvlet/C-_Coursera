#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    Person (const string &first_name, const string &last_name, int year) {
        birth_year = year;
        names.push_back({year, first_name});
        surnames.push_back({year, last_name});
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year < birth_year)
            return;

        names.push_back({year, first_name});
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year < birth_year)
            return;

        surnames.push_back({year, last_name});
    }
    string GetFullName(int year) {
        if (year < birth_year)
            return "No person";

        string first_name = find_name(year, names);
        string last_name = find_name(year, surnames);
        return get_full_name(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) {
        if (year < birth_year)
            return "No person";

        sort(begin(names), end(names));
        sort(begin(surnames), end(surnames));

        string first_names = parse_vec2str(find_array_of_names(year, names));
        string last_names = parse_vec2str(find_array_of_names(year, surnames));

        return get_full_name(first_names, last_names);
    }
private:
    int birth_year;
    vector < pair<int, string> > names;
    vector < pair<int, string> > surnames;

    /*
    Получается в ввод имя и фамилию
    возвращает их в виде вывода который
    просится в задаче
    */
    string get_full_name (const string& first_name, const string& last_name) {
        if (first_name != "" and last_name != "")
            return first_name + " " + last_name;
        else if (first_name == "" and last_name != "")
            return last_name + " with unknown fist name";
        else if (first_name != "" and last_name == "")
            return first_name + " with unknown last name";
        return "incognito";
    }

    /*
    Возвращает имя/фамилию из списка если же
    то считается валидным для данного года.
    Выбирает самый последний год 
    изменения имени/фамилии
    */
    string find_name (int year, const vector<pair<int, string>>& v) {
        string name = "";
        int year_name = -1;

        for (const auto& i: v) {
            if (year >= i.first and year_name < i.first) {
                name = i.second;
                year_name = i.first;
            }
        }

        return name;
    }

    /*
    Возвращает массив имён/фамилий из списка если, же
    те считаются валидным для данного года.
    Так же удаляются повторения имён/фамлий
    */
    vector<string> find_array_of_names (int year, const vector<pair<int, string>>& v) {
        vector<string> array_of_names;
        string last_element = "";
        
        for (const auto& i: v) {
            if (year >= i.first and last_element != i.second) {
                array_of_names.push_back(i.second);
                last_element = i.second;
            }
            else 
                break;
        }

        return array_of_names;
    }

    /*
    Парсит наш вектор в крассивую строку для вывода
    */
    string parse_vec2str (const vector<string>& v) {
        if (v.empty())
            return "";
        if (v.size() == 1)
            return v.back();
        string res = v.back() + " (";
        for (int i = v.size() - 2; i >= 0; --i)
            res += v[i] + (i != 0 ? ", " : ")");
        
        return res;
   }
};
