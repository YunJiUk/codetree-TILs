#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int num1, num2, num3, num4;

vector<vector<int>> v1;

unordered_set<int> us1;


void init() {

}

void input() {

    cin >> num1 >> num2;
    v1.resize(num2);
    us1.insert(1);

    int ansflag = 0;
    for (int n1 = 0; n1 < num2; n1++) {
        cin >> num3;
        v1[n1].resize(num3);


        for (int n2 = 0; n2 < num3; n2++) {
            cin >> num4;
            v1[n1][n2] = num4;
        }
    }

    while (1) {
        int ansflag = 0;

        for (int n1 = 0; n1 < num2; n1++) {
            int cnt = 0;
            int ins = 0;
            int flag = 1;
            for (int n2 = 0; n2 < v1[n1].size(); n2++) {
                if (us1.find(v1[n1][n2]) == us1.end()) {
                    if (cnt == 1) {
                        flag = 1;
                        continue;
                    }
                    ins = v1[n1][n2];
                    cnt++;
                    flag = 0;
                }
            }
            if (flag == 0) {
                ansflag = 1;
                us1.insert(ins);
                break;
            }
        }

        if (ansflag == 0) return;
    }


}

void solve() {
    cout << us1.size();
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();

    input();

    solve();

    return 0;
}