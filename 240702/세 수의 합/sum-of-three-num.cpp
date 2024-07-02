#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int num1, num2;
int num3;

unordered_map<int, int> um1;
unordered_map<int, int> um2;

void init() {
    // 초기화 코드가 있다면 여기에 작성
}

void input() {
    cin >> num1 >> num2;
    vector<int> nums(num1);
    
    for (int i = 0; i < num1; i++) {
        cin >> nums[i];
        um1[nums[i]]++;
    }

    int ans = 0;
    
    for (int i = 0; i < num1; i++) {
        num3 = nums[i];
        um1[num3]--;
        
        if (um2.count(num2 - num3) != 0) {
            ans += um2[num2 - num3];
        }
        
        for (auto item : um1) {
            if (item.second > 0) {
                um2[item.first + num3]++;
            }
        }
    }

    cout << ans;
}

void solve() {
    // 문제 해결 코드가 있다면 여기에 작성
}

int main() {
    init();
    input();
    solve();
    return 0;
}