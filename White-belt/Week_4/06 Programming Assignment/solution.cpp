#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            if (j+1 != M)
                cin.ignore(1);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(10) << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
