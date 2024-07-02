#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int num1, num2, num3;
unordered_map<int, int> um1;


void init() {

}

void input() {
    cin >> num1 >> num2;
    for (int n1 = 0; n1 < num1; n1++) {
        vector<int> v1;
        cin >> num3;
        um1[num3]++;

        for (auto item : um1) {
            
            if (item.first != num3) {
                v1.push_back(item.first + num3);
            }
        }

        for (int n1 = 0; n1 < v1.size(); n1++) {
            um1[v1[n1]]++;
        }
    }

    cout << um1[num2];
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