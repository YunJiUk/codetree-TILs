#include <iostream>
#include <set>

using namespace std;

int num1, num2, num3;

set<int> s1;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> num1 >> num2;

    for(int n1 = 0; n1 < num1; n1++){
        cin >> num3;
        s1.insert(num3);
    }

    for(int n1  = 0; n1 < num2; n1++){
        cin >> num3;

        if(s1.lower_bound(num3) != s1.end()){
            cout << *s1.lower_bound(num3) << endl;
        }

        else{
            cout << -1 << endl;
        }
    }

    return 0;
}