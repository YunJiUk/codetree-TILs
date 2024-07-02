#include <iostream>
#include <unordered_map>

using namespace std;

int num1, num2, num3;

unordered_map<int, int> um1;

void init(){

}

void input(){
    cin >> num1;

    for(int n1 = 0; n1 < num1; n1++){
        cin >> num2 >> num3;
        if(um1.find(num2) == um1.end()){
            um1[num2] = num3;
        }
        else if(um1[num2] > num3){
            um1[num2] = num3;
        }
    }
}

void solve(){
    long long ans = 0;
    for(auto item : um1){
        ans += item.second;
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