#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    int _sz = v.size();

    for (int i = 0; i < _sz / 2; ++i) {
        swap(v[i], v[_sz - i - 1]);
    }
}

int main() {
    return 0;
}
