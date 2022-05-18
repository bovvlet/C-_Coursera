#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");

    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "file didn't open";
    }
}