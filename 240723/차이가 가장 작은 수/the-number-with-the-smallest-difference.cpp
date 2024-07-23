#include <iostream>
#include <set>
using namespace std;

int num1, num2, num3;
int maxans = 2134567890;
set<int> s1;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> num1;
    cin >> num2;

    for(int n1 = 0; n1 < num1; n1++){
        cin >> num3;

        auto pointer1 = s1.lower_bound(num3);
        s1.insert(num3);
        auto pointer2 = s1.lower_bound(num3);

        if(pointer2 != s1.begin()){
            pointer2--;

            int check = num3 - *pointer2;
            if(check >= num2 && maxans > check){
                maxans = check;
            }
        }

        if(pointer1 != s1.end()){
            int check = *pointer1 - num3;
            if(check >= num2 && maxans > check){
                maxans = check;
            }
        }
    }

    if(maxans == 2134567890){
        cout << -1;
    }
    else{
        cout << maxans;
    }

    return 0;
}