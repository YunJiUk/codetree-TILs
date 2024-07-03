#include <iostream>
#include <map>
#include <string>

using namespace std;

int num1, num2;

string str1;

map<string, double> m1;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> str1;
        m1[str1]++;
    }
}

void solve(){
    for(auto item : m1){
        cout << item.first << " ";
        printf("%.4lf\n", double(item.second / num1) * 100);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}