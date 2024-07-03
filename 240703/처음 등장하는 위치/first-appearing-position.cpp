#include <iostream>
#include <map>

using namespace std;

map<int, int> m1;

int num1, num2;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 1; n1 <= num1; n1++){
        cin >> num2;
        if(m1.find(num2) == m1.end()){
            m1[num2] = n1;
        }
    }
}

void solve(){
    for(auto item : m1){
        cout << item.first << " " << item.second << endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}