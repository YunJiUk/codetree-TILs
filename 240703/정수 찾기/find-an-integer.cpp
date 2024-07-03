#include <iostream>
#include <unordered_set>

using namespace std;

int num1, num2;
unordered_set<int> us1;

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
        cin>> num2;
        if(us1.find(num2) == us1.end()){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
}

void solve(){

}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    input();

    solve();

    return 0;
}