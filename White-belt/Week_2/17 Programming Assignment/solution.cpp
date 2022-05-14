#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, set<string>>mp;

void add() {
    string word1, word2;
    cin >> word1 >> word2;

    mp[word1].insert(word2);
    mp[word2].insert(word1);
}

void count() {
    string word;
    cin >> word;
    cout << mp[word].size() << endl;
}

void check() {
    string word1, word2;
    cin >> word1 >> word2;

    if (mp.count(word1) != 0 and mp[word1].count(word2) != 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int Q;
    cin >> Q;

    while (Q --) {
        string command;
        cin >> command;

        if (command == "ADD")
            add();
        else if (command == "COUNT")
            count();
        else if (command == "CHECK")
            check();

    }
    return 0;
}
