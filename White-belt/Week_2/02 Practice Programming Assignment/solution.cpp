#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom (string s) {
    int _sz = s.size();

    for (int i = 0; i < _sz/2; ++i) {
        if (s[i] != s[_sz-i-1])
            return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    if (IsPalindrom(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}
