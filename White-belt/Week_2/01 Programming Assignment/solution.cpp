#include <iostream>

using namespace std;

int Factorial (int N) {
    if (N < 0)
        return -1;
    else if (N < 2)
        return 1;
    else
        return N * Factorial(N - 1);
}

int main() {
    int N;
    cin >> N;

    cout << Factorial(N);

    return 0;
}
