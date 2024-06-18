#include <iostream>
#include <cmath>

using namespace std;

int num1, num2, num3;
int Map[101];
int minans;

void init(){
    minans = 2134567890;
}

void input(){
    cin >> num1 >> num2 >> num3;

    for(int n1 =0; n1 < num1; n1++){
        cin >> Map[n1];
    }
}

void solve(){
    int ans;
    for(int n1 = 0; n1 <= num1 - num3; n1++){
        ans = 0;
        for(int n2 = 0; n2 < num3; n2++){
            ans += abs(Map[n1 + n2] - num2);
            //cout << ans << endl;
        }
        if(ans < minans){
            minans = ans;
        }
    }

    
}

int main() {
    init();

    input();

    solve();

    cout << minans;
    // 여기에 코드를 작성해주세요.
    return 0;
}