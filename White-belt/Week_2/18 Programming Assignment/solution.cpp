#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map<set<string>, int>mp;

int main() {
    int Q;
    cin >> Q;

    while (Q --) {
        int N;
        cin >> N;

        set<string>bus;
        for (int i = 0; i < N; ++i) {
            string stop;
            cin >> stop;

            bus.insert(stop);
        }

        if (mp.find(bus) == mp.end()) {
            mp[bus] = int(mp.size()) + 1;
            cout << "New bus " << mp.size() << endl;
        }
        else {
            cout << "Already exists for " << mp[bus] << endl;
        }
    }
    return 0;
}
