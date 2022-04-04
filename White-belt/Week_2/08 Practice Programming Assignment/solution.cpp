#include <iostream>
#include <vector>

using namespace std;

int mean_of_array (const vector<int> &v) {
    int sum = 0;
    int N = v.size();

    for (auto k: v) {
        sum += k;
    }

    return sum / N;
}

int main() {
    int N;
    cin >> N;

    vector<int>v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int mean = mean_of_array(v);

    vector<int>greater_than_mean;
    for (int i = 0; i < N; ++i) {
        if (v[i] > mean) {
            greater_than_mean.push_back(i);
        }
    }

    cout << greater_than_mean.size() << endl;
    for (auto k: greater_than_mean) {
        cout << k << " ";
    }
    return 0;
}
