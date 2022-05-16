#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int>v(N);
    for (auto& i: v) {
        cin >> i;
    }

    sort(begin(v), end(v), [](int a, int b) {
        return abs(a) < abs(b);
    });

    for (const auto& i: v) {
        cout << i << " ";
    }

    return 0;
}
