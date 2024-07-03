#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> us1;

int num1;
int num2;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> num2;
        us1.insert(num2);
    }

    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> num2;
        if(us1.find(num2) == us1.end()){
            cout << 0 << " ";
        }
        else{
            cout << 1 << " ";
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