#include <iostream>
#include <set>

using namespace std;

set<int> s1;

int num1, num2, num3;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> num1 >> num2;

    int cnt = 0;

    for(int n1 = 1; n1 <= num2; n1++){
        s1.insert(n1);
    }

    for(int n1 = 0; n1 < num1; n1++){
        cin >> num3;
        if(s1.upper_bound(num3) == s1.begin()){
            cout << cnt;
            return 0;
        }

        auto item = s1.upper_bound(num3);

        item--;

        s1.erase(*item);

        cnt++;
    }

    return 0;
}