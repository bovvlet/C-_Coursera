#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        names.push_back({year, first_name});
    }
    void ChangeLastName(int year, const string& last_name) {
        surnames.push_back({year, last_name});
    }
    string GetFullName(int year) {
        string first_name = find_name(year, names);
        string last_name = find_name(year, surnames);

        if (first_name != "" and last_name != "")
            return first_name + " " + last_name;
        else if (first_name == "" and last_name != "")
            return last_name + " with unknown fist name";
        else if (first_name != "" and last_name == "")
            return first_name + " with unknown last name";
        return "incognito";
    }
private:
    vector < pair<int, string> > names;
    vector < pair<int, string> > surnames;

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
};

int main() {
  return 0;
}