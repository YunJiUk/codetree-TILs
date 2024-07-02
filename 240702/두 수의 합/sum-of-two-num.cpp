#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int num1, num2, num3;

unordered_map<int, int> um1; 

int ans = 0;

struct Node {
    int num;
    int size;
};


void init() {

}

void input() {
    cin >> num1 >> num2;
    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num3;

        ans += um1[num2 - num3];

        um1[num3]++;
    }

    cout << ans;
}

void solve() {

}

int main() {
    init();

    input();

    solve();
    // 여기에 코드를 작성해주세요.
    return 0;
}