#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString () {
        str = "";
    }
    ReversibleString (const string& s) {
        str = s;
    }
    void Reverse () {
        reverse(begin(str), end(str));
    }
    string ToString () const {
        return str;
    }
private:
    string str;
};


