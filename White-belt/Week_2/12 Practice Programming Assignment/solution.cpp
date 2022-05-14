#include <iostream>
#include <map>

using namespace std;

map<string,string>mp;

void change_capital() {
    string country, new_capital;
    cin >> country >> new_capital;

    if (mp.count(country) == 0)
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    else if (mp[country] == new_capital)
        cout << "Country " << country << " hasn't changed its capital" << endl;
    else if (mp[country] != new_capital)
        cout << "Country " << country << " has changed its capital from " << mp[country] << " to " << new_capital << endl;

    mp[country] = new_capital;
}

void rename() {
    string old_country_name, new_country_name;
    cin >> old_country_name >> new_country_name;

    bool check = true;

    if (old_country_name == new_country_name)
        check = false;
    if (mp.count(old_country_name) == 0 or mp.count(new_country_name) == 1)
        check = false;

    if (check == false)
        cout << "Incorrect rename, skip" << endl;
    else {
        string capital = mp[old_country_name];
        mp[new_country_name] = capital;
        mp.erase(old_country_name);
        cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
    }
}

void about() {
    string country;
    cin >> country;

    if (mp.count(country) == 0)
        cout << "Country " << country << " doesn't exist" << endl;
    else
        cout << "Country " << country << " has capital " << mp[country] << endl;
}

void dump() {
    if (mp.empty())
        cout << "There are no countries in the world" << endl;
    else {
        for (const auto& [country, capital]: mp) {
            cout << country << "/" << capital << " ";
        }
        cout << endl;
    }
}

int main() {
    int Q;
    cin >> Q;
    while(Q --) {
        string command;
        cin >> command;

        if (command == "CHANGE_CAPITAL")
            change_capital();
        else if (command == "RENAME")
            rename();
        else if (command == "ABOUT")
            about();
        else if (command == "DUMP")
            dump();
    }

    return 0;
}
