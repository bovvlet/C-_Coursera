#include <iostream>

using namespace std;

int main() {

    string A, B, C;
    cin >> A >> B >> C;

    if (A <= B and A <= C) {
        cout << A << endl;
    }
    else if (B <= A and B <= C) {
        cout << B << endl;
    }
    else if (C <= A and C <= B) {
        cout << C << endl;
    }

    return 0;
}
