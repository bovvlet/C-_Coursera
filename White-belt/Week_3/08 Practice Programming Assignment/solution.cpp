#include <iostream>

using namespace std;

class Incognizable {
public:
    Incognizable () {}
    Incognizable (int first) {
        this->first = first;
    }
    Incognizable (int first, int second) {
        this->first = first;
        this->second = second;
    }
private:
    int first;
    int second;
};

int main() {
  return 0;
}
