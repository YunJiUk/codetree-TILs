#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int num1;
string str1;
unordered_map<string, int> um1;

int ans = 0;

void init(){

}

void input(){
    cin >> num1;

    for(int n1 = 0; n1 < num1; n1++){
        cin >> str1;
        sort(str1.begin(), str1.end());

        um1[str1]++;
        if(um1[str1] > ans){
            ans = um1[str1];
        }
    }
}

void solve(){
    cout << ans;
}


int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}