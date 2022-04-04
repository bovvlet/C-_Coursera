#include <iostream>
#include <string>

using namespace std;

int gcd (int A, int B) {

    if (A == 0) {
        return B;
    }

    return gcd(B % A, A);
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << gcd(A, B);
    return 0;
}
