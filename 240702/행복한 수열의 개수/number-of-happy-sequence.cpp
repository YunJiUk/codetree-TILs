#include <iostream>

using namespace std;

int num1, num2, num3, num4, num5;

int cnt = 0;

int Map[10000][10000];

void init() {

}

void input() {
    cin >> num1 >> num2;

    for(int n1 = 0; n1 < num1; n1++){
        for(int n2 = 0; n2 < num1; n2++){
            cin >>Map[n1][n2];
        }
    }
}

void solve() {
    for(int n1 = 0; n1 < num1; n1++){
        for(int n2 = 0; n2 < num1 - 1; n2++){
            if(Map[n1][n2] == Map[n1][n2 + 1]){
                cnt++;
                break;
            }
        }
    }

    for(int n1 = 0; n1 < num1; n1++){
        for(int n2 = 0; n2 < num1 - 1; n2++){
            if(Map[n2][n1] == Map[n2 + 1][n1]){
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
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