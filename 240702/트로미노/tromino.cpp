#include <iostream>

using namespace std;

int num1, num2, num3, num4, num5;

int Map[10000][10000];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct check {
    int p1;
    int p2;
};

check arr[4] = { {0,1}, {1, 2}, {2, 3}, {3, 0} };
check arr2 = { 0,2 };
check arr3 = { 1,3 };

void init() {

}

void input() {
    cin >> num1 >> num2;
    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            cin >> Map[n1][n2];
        }
    }
}

void solve() {
    int realans = -2134567890;

    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            int ans = 0;

            int ny1 = n1 + dy[arr2.p1];
            int nx1 = n2 + dx[arr2.p1];

            int ny2 = n1 + dy[arr2.p2];
            int nx2 = n2 + dx[arr2.p2];

            if (ny1 < 0 || ny1 >= num1
                || nx1 < 0 || nx1 >= num2
                || ny2 < 0 || ny2 >= num1
                || nx2 < 0 || ny2 >= num2) continue;

            ans = Map[ny1][nx1] + Map[ny2][nx2] + Map[n1][n2];

            if (ans > realans) {
                realans = ans;
            }

            ans = 0;

            ny1 = n1 + dy[arr3.p1];
            nx1 = n2 + dx[arr3.p1];

            ny2 = n1 + dy[arr3.p2];
            nx2 = n2 + dx[arr3.p2];

            if (ny1 < 0 || ny1 >= num1
                || nx1 < 0 || nx1 >= num2
                || ny2 < 0 || ny2 >= num1
                || nx2 < 0 || ny2 >= num2) continue;

            ans = Map[ny1][nx1] + Map[ny2][nx2] + Map[n1][n2];

            if (ans > realans) {
                realans = ans;
            }
        }
    }



    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            

            for (int n3 = 0; n3 < 4; n3++) {
                int ans = 0;
                int ny1 = n1 + dy[arr[n3].p1];
                int nx1 = n2 + dx[arr[n3].p1];

                int ny2 = n1 + dy[arr[n3].p2];
                int nx2 = n2 + dx[arr[n3].p2];

                if (ny1 < 0 || ny1 >= num1
                    || nx1 < 0 || nx1 >= num2
                    || ny2 < 0 || ny2 >= num1
                    || nx2 < 0 || ny2 >= num2) continue;

                ans += Map[ny1][nx1] + Map[ny2][nx2] + Map[n1][n2];

                if (ans > realans) {
                    realans = ans;
                }
            }
        }
    }

    cout << realans;
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