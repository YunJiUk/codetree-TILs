#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int num1, num2, num3;
string str1;

unordered_map<int, int> um1;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> str1;

        if(str1 == "add"){
            cin >> num2 >> num3;
            um1[num2] = num3;
        }

        else if(str1 == "find"){
            cin >> num2;
            if(um1.find(num2) != um1.end()){
                cout << um1[num2] << endl;
            }
            else{
                cout << "None" << endl;
            }
        }
        else if(str1 == "remove"){
            cin >> num2;
            um1.erase(num2);
        }
    }

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