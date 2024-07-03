#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int num1, num2;
string str1;

unordered_set<int> us1;

void init(){

}

void input(){
    cin >> num1;

    for(int n1 = 0; n1 < num1; n1++){
        cin >> str1;
        if(str1 == "find"){
            cin >> num2;
            if(us1.find(num2) != us1.end()){
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
        }
        else if(str1 == "remove"){
            cin >> num2;
            us1.erase(num2);
        }
        else if(str1 == "add"){
            cin >> num2;
            us1.insert(num2);
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