#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int num1, num2;
int num3;

unordered_map<int, int>um1;
unordered_map<int, int>um2;
unordered_map<int, int>um3;


void init() {

}

void input() {
    cin >> num1 >> num2;
    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num3;

        for (auto item : um2) {
            um3[item.first + num3] += um2[item.first];
        }

        for (auto item : um1) {
            um2[item.first + num3] += um1[item.first];
        }

        um1[num3]++;
    }

    cout << um3[num2];
}

void solve() {

}

int main() {
    // 여기에 코드를 작성해주세요.

    init();

    input();

    solve();

    return 0;
}