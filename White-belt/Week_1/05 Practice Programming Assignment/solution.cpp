#include <iostream>

using namespace std;

int main() {

    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;

    if (N > B) {
        N *= (100 - Y) / 100.0;
    }
    else if (N > A) {
        N *= (100 - X) / 100.0;
    }

    cout << N << endl;

    return 0;
}
