#include <iostream>

using namespace std;

void rec (int N) {
    if (N == 0)
        return;

    rec(N / 2);
    cout << N % 2;
}

int main() {
    int N;
    cin >> N;

    rec(N);

    return 0;
}
