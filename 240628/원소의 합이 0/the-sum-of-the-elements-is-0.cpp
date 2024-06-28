#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int num1;
int num2;
int ans = 0;

unordered_map<int, int> um1;
unordered_map<int, int> um2;

int arr[4][1000001];


void init() {

}

void input() {
    cin >> num1;
    for (int n1 = 0; n1 < 4; n1++) {
        for (int n2 = 0; n2 < num1; n2++) {
            cin >> arr[n1][n2];
        }
    }
}

void solve() {
    for (int n1 = 0; n1 < num1; n1++) {
        int fnum = arr[0][n1];
        for (int n2 = 0; n2 < num1; n2++) {
            int snum = arr[1][n2];

            um1[fnum + snum]++;
        }
    }

    for (int n1 = 0; n1 < num1; n1++) {
        int fnum = arr[2][n1];
        for (int n2 = 0; n2 < num1; n2++) {
            int snum = arr[3][n2];

            um2[fnum + snum]++;
        }
    }

    for (auto item : um1) {
        if (um2[item.first * -1] != 0) {
            ans += item.second * um2[item.first * -1];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    input();

    solve();

    cout << ans;

    return 0;
}