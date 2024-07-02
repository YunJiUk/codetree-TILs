#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string str1;
int num1;
int maxcnt = 0;

unordered_map<string, int> um1;


void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> str1;
        um1[str1]++;
        if(um1[str1] > maxcnt){
            maxcnt = um1[str1];
        }
    }

    cout << maxcnt;
}

void solve(){

}

int main() {
    // 여기에 코드를 작성해주세요.

    init();

    input();

    solve();

    return 0;
}