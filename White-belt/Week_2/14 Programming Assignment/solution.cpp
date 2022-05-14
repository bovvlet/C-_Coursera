#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<vector<string>, int>mp;

int main() {
    int Q;
    cin >> Q;

    while (Q --) {
        int N;
        cin >> N;

        vector<string>bus;
        for (int i = 0; i < N; ++i) {
            string stop;
            cin >> stop;

            bus.push_back(stop);
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
