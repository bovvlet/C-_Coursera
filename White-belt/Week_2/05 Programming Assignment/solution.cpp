#include <iostream>
#include <vector>

using namespace std;

void MoveStrings (vector<string> &source, vector<string> &destination) {
    for (auto k: source) {
        destination.push_back(k);
    }
    source.clear();
}

int main() {
    return 0;
}
