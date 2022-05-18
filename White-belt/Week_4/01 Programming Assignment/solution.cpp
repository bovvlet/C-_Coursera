#include <iostream>

using namespace std;

struct Specialization {
    explicit Specialization (const string& new_data) {
        data = new_data;
    }
    string data;
};

struct Course {
    explicit Course (const string& new_data) {
        data = new_data;
    }
    string data;
};

struct Week {
    explicit Week (const string& new_data) {
        data = new_data;
    }
    string data;
};

struct LectureTitle {
    LectureTitle (const Specialization& s, const Course& c, const Week& w) {
        specialization = s.data;
        course = c.data;
        week = w.data;
    }
    string specialization;
    string course;
    string week;
};

int main() {
    return 0;
}