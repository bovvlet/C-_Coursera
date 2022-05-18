#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
        }
        return result;
    }
    void Invert() {
        for (Part& p: parts) {
            if (p.operation == '+')
                p.operation = '-';
            else if (p.operation == '-')
                p.operation = '+'; 
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<Part> parts;
};
int main() {
  return 0;
}