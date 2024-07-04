#include <iostream>
#include <unordered_set>

using namespace std;

int num1, num2, num3, num4;

unordered_set<int> us1;
unordered_set<int> us2;
unordered_set<int> us3;


void init(){

}

void input(){
    cin >> num1 >> num2;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> num3;
        us1.insert(num3);
    }

    for(int n1 = 0; n1 < num2; n1++){
        cin >> num4;
        us2.insert(num4);

        if(us1.find(num4) != us1.end()){
            us3.insert(num4);
        }
    }
}

void solve(){
    for(auto item : us1){
        if(us2.find(item) != us2.end()){
            us3.insert(item);
        }
    }

    cout << us3.size();
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}