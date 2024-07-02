#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int num1, num2, num3;
string str1, str2;

unordered_map<string, int> um1;
unordered_map<int, string> um2;

void init(){

}

void input(){
    cin >> num1 >> num2;

    for(int n1 = 1; n1 <= num1; n1++){
        cin >> str1;
        um1[str1] = n1;
        um2[n1] = str1;
    }

    for(int n1 = 0; n1 < num2; n1++){
        cin >> str2;
        if(str2[0] >='0' && str2[0] <='9'){
            cout << um2[stoi(str2)] << endl;
        }

        else{
            cout << um1[str2] << endl;
        }
    }
}

void solve(){

}

int main() {
    init();

    input();

    solve();

    // 여기에 코드를 작성해주세요.
    return 0;
}