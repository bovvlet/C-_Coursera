#include <iostream>
#include <set>

using namespace std;

set<string>words;

int main() {
    int Q;
    cin >> Q;

    while (Q --) {
        string s;
        cin >> s;

        words.insert(s);
    }

    cout << words.size();
    return 0;
}
