#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> us1;

int num1, num2;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> num2;
        us1.insert(num2);
    }
}

void solve(){
    cout << us1.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    input();

    solve();
    // 여기에 코드를 작성해주세요.
    return 0;
}