#include <iostream>
#include <vector>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void next (int &cur_month, vector<vector<string>> &tasks) {
    cur_month = (cur_month + 1) % 12;
    int day_numb = days[cur_month];

    if (tasks.size() > day_numb) {
        while (tasks.size() != day_numb) {
            vector<string>v = tasks.back();
            tasks.pop_back();

            tasks[day_numb-1].insert(end(tasks[day_numb-1]), begin(v), end(v));
        }
    }

    else if (tasks.size() < day_numb) {
        while (tasks.size() != day_numb) {
            vector<string>v; /// пустой вектор
            tasks.push_back(v);
        }
    }
    return;
}

void dump (int x, const vector<vector<string>> &tasks) {
    cout << tasks[x-1].size();

    for (auto k: tasks[x-1]) {
        cout << " " << k;
    }

    cout << endl;
    return;
}

void add (int x, string s, vector<vector<string>> &tasks) {
    tasks[x - 1].push_back(s);
    return;
}

int main() {

    int cur_month = 0;
    vector<vector<string>> tasks(31);

    int t;
    cin >> t;
    while (t --) {
        string op;
        cin >> op;

        if (op == "NEXT") {
            next(cur_month, tasks);
        }
        else if (op == "DUMP") {
            int x;
            cin >> x;
            dump (x, tasks);
        }
        else if (op == "ADD") {
            int x;
            string s;
            cin >> x >> s;

            add (x, s, tasks);
        }
    }
    return 0;
}
