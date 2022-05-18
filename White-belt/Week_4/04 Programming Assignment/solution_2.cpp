#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    if (!input) {
        cout << "input file didn't open";
    }
    else if (!output) {
        cout << "output file didn't open";
    }
    else {
        string line;
        while (getline(input, line)) {
            output << line << endl;
        }
    }
}