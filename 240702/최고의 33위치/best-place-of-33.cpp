#include <iostream>

using namespace std;

int num1, num2, num3, num4, num5;
int Map[10000][10000];

int maxcnt = -2134567890;

void init() {

}

void input() {
    cin >> num1;
    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num1; n2++) {
            cin >> Map[n1][n2];
        }
    }
}

void solve() {
    for (int n1 = 0; n1 < num1 - 2; n1++) {
        for (int n2 = 0; n2 < num1 - 2; n2++) {
            int cnt = 0;
            for (int n3 = 0; n3 < 3; n3++) {
                for (int n4 = 0; n4 < 3; n4++) {
                    if (Map[n1 + n3][n2 + n4] == 1) cnt++;
                }
            }

            if (cnt > maxcnt) {
                maxcnt = cnt;
            }
        }
    }

    cout << maxcnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    input();

    solve();

    return 0;
}