#include <iostream>
#include <string>
#include <map>

using namespace std;

int num1, num2, num3;
string str1;

map<int, int> m1;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
    cin >> str1;
    if(str1 == "add"){
        cin >> num2 >> num3;
        m1[num2] = num3;
    }

    if(str1 == "find"){
        cin >> num2;
        if(m1.find(num2) != m1.end()){
            cout << m1[num2] << endl;
        }
        else{
            cout << "None" << endl;
        }
    }

    if(str1 == "remove"){
        cin >> num2;
        m1.erase(num2);
    }

    if(str1 == "print_list"){
        if(m1.size() == 0){
            cout << "None" << endl;
        }
        else{
            for(auto item : m1){
                cout << item.second << " ";
            }
        }
        cout << endl;
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