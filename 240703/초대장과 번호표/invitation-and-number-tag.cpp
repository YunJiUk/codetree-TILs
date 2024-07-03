#include <iostream>
#include <unordered_set>

using namespace std;

int num1, num2, num3, num4;

unordered_set<int> us1;

void init() {

}

void input() {
    cin >> num1 >> num2;
    us1.insert(1);
    for (int n1 = 0; n1 < num2; n1++) {
        cin >> num3;
        int cnt = 0;
        int ins = 0;
        int flag = 1;
        for (int n2 = 0; n2 < num3; n2++) {
            cin >> num4;
            if (us1.find(num4) == us1.end()) {
                if (cnt != 0) {
                    flag = 0;
                    continue;
                }
                ins = num4;
                cnt++;
            }
        }

        if (flag == 1) us1.insert(ins);
    }
}

void solve() {
    cout << us1.size();
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}