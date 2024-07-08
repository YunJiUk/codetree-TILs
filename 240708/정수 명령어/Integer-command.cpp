#include <iostream>
#include<set>

using namespace std;

int num1, num2, num3;

set <int> s1;

void init(){

}

void input(){
    cin >> num1;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> num2;

        for(int n2 = 0; n2 < num2; n2++){
            char c1;
            cin >> c1;

            if(c1 == 'I'){
                cin >> num3;
                s1.insert(num3);
            }

            if(c1 == 'D'){
                cin >> num3;

                if(s1.size() > 0){
                if(num3 == 1){
                    s1.erase(*s1.rbegin());
                }

                else if(num3 == -1){
                    s1.erase(*s1.begin());
                }
                }
            }
        }

        if(s1.size() == 0){
            cout << "EMPTY" << endl;
        }

        else{
            cout << *s1.rbegin() << " " << *s1.begin() << endl;
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