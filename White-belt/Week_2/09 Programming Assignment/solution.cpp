#include <iostream>
#include <vector>

using namespace std;

void worry (int i, vector<int> &v) {
    v[i] = 1;
    return;
}

void quiet (int i, vector<int> &v) {
    v[i] = 0;
    return;
}

void come (int k, vector<int> &v) {
    if (k > 0) {
        while (k --) {
            v.push_back(0);
        }
    }
    else {
        while (k ++) {
            v.pop_back();
        }
    }
    return;
}

int worry_count (vector<int> &v) {
    int res = 0;
    for (auto k: v) {
        res += k;
    }
    return res;
}

int main() {
    vector<int>v;

    int t;
    cin >> t;
    while (t --) {
        string op;
        cin >> op;

        if( op == "WORRY_COUNT" ) {
            cout << worry_count(v) << endl;
        }
        else {
            int x;
            cin >> x;

            if (op == "WORRY") {
                worry(x, v);
            }
            else if (op == "QUIET") {
                quiet(x, v);
            }
            else if (op == "COME") {
                come(x, v);
            }
        }
    }
    return 0;
}
