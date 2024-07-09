#include <iostream>
#include <set>
using namespace std;

int num1, num2, num3;
int minans = 2134567890;

set<int> s1;

int main() {
    cin >> num1 >> num2;

    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num3;
        
        // 새 값을 set에 삽입하기 전에 주변 값을 체크합니다.
        auto item = s1.lower_bound(num3);
        
        if (item != s1.begin()) {
            auto prev_item = prev(item);
            if ((num3 - *prev_item) > num2 && (num3 - *prev_item) < minans) {
                minans = num3 - *prev_item;
            }
        }

        if (item != s1.end()) {
            if ((*item - num3) > num2 && (*item - num3) < minans) {
                minans = *item - num3;
            }
        }
        
        // 새로운 값을 set에 삽입합니다.
        s1.insert(num3);
    }

    if (minans == 2134567890) {
        cout << -1;
    } else {
        cout << minans;
    }

    return 0;
}