#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> v(N, "");
    for (auto& i: v) {
        cin >> i;
    }

    sort(begin(v), end(v),
        [](const string& a, const string& b) {
            return lexicographical_compare(begin(a), end(a), begin(b), end(b),
                [](char x, char y) {
                return toupper(x) < toupper(y);
                }
            );
        }
    );

    for (const auto& i: v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
