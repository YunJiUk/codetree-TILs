#include <iostream>
#include <set>
using namespace std;

int num1, num2;
int ansmin = 2134567890; // 큰 값으로 초기화

set<int> s1;

int main() {
    cin >> num1;
    s1.insert(0);

    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num2;
        s1.insert(num2);

        // upper_bound를 사용하여 num2보다 큰 값을 찾고 차이를 계산
        if (s1.upper_bound(num2) != s1.end()) {
            int check = *s1.upper_bound(num2) - num2;
            if (check < ansmin) {
                ansmin = check;
            }
        }

        // num2보다 작은 값과의 차이를 계산
        auto it = s1.lower_bound(num2);
        if (it != s1.end()) {
            --it;
            int check = num2 - *it;
            if (check < ansmin) {
                ansmin = check;
            }
        }

        cout << ansmin << endl;
    }

    
    return 0;
}