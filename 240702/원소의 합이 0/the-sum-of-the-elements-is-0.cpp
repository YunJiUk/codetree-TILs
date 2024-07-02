#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int num1, num2;

unordered_map<int, int> um1;

vector<int> v1[4];

void init() {

}

void input() {
    cin >> num1;
    for (int n1 = 0; n1 < 4; n1++) {
        v1[n1].resize(num1);
    }

    for (int n1 = 0; n1 < 4; n1++) {
        for (int n2 = 0; n2 < num1; n2++) {
            cin >> num2;
            v1[n1][n2] = num2;
        }
    }


}

void solve() {
    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num1; n2++) {
            um1[v1[0][n1] + v1[1][n2]]++;
        }
    }

    int ans = 0;
    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num1; n2++) {
            if (um1.count((v1[2][n1] + v1[3][n2]) * -1) != 0) {
                ans += um1[(v1[2][n1] + v1[3][n2]) * -1];
            }
        }
    }

    cout << ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}