#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom (string s) {
    int _sz = s.size();

    for (int i = 0; i < _sz/2; ++i) {
        if (s[i] != s[_sz-i-1])
            return false;
    }

    return true;
}

vector<string> PalindromFilter (vector<string> V, int minLength) {
    vector<string>res;

    for (auto k: V) {
        if (IsPalindrom(k) and k.size() >= minLength)
            res.push_back(k);
    }

    return res;
}

int main() {
    string s;
    getline(cin, s);

    int min_Length;
    cin >> min_Length;


    string cur = "";
    vector<string> V;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ')
            continue;
        if (s[i] == ',') {
            V.push_back(cur);
            cur = "";
        }
        else {
            cur += s[i];
        }
    }
    V.push_back(cur);

    vector<string>res = PalindromFilter(V, min_Length);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i+1 == res.size() ? "" : ", ");
    }

    return 0;
}
