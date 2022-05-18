#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<char, char>invert_op{{'+','-'}, {'-','+'}, {'*','/'}, {'/','*'}};

struct Part {
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }
    double Apply(double value) {
        double result = value;
        for (const Part& p: parts) {
            if (p.operation == '+')
                result += p.value;
            else if (p.operation == '-')
                result -= p.value;
            else if (p.operation == '*')
                result *= p.value;
            else if (p.operation == '/')
                result /= p.value;
        }
        return result;
    }
    void Invert() {
        for (Part& p: parts) {
            p.operation = invert_op[p.operation];
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<Part> parts;
};

int main() {
    return 0;
}
