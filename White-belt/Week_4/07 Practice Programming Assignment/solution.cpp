#include <iostream>

using namespace std;

struct Fullname {
    string name;
    string surname;
};

struct Date {
    int day = 1;
    int month = 1;
    int year = 1970;
};

struct Student {
    Date date;
    Fullname fullname;
};

istream& operator>>(istream& stream, Fullname& fullname) {
    stream >> fullname.name >> fullname.surname;
    return stream;
}

ostream& operator<<(ostream& stream, Fullname& fullname) {
    stream << fullname.name << " " << fullname.surname;
    return stream;
}

istream& operator>>(istream& stream, Date& date) {
    stream >> date.day >> date.month >> date.year;
    return stream;
}

ostream& operator<<(ostream& stream, Date& date) {
    stream << date.day << "." << date.month << "." << date.year;
    return stream;
}

istream& operator>>(istream& stream, Student& student) {
    stream >> student.fullname >> student.date;
    return stream;
}

int main() {
    int N;
    cin >> N;

    Student students[N] = {};
    for (int i = 0; i < N; ++i) {
        cin >> students[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string op;
        int idx;
        cin >> op >> idx;
        if (op == "name" and (idx > 0 and idx <= N)) {
            cout << students[idx-1].fullname << endl;
        } else if (op == "date" and (idx > 0 and idx <= N)) {
            cout << students[idx-1].date << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}
