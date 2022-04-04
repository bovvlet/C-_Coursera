#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int flag = -2;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            if (flag == -2) {
                flag = -1;
            }
            else if (flag == -1) {
                flag = i;
            }
        }
    }

    cout << flag;

    return 0;
}
