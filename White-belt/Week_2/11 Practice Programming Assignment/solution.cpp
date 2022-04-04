#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --) {
        string a, b;
        cin >> a >> b;

        sort (begin(a), end(a));
        sort (begin(b), end(b));

        if (a == b) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
