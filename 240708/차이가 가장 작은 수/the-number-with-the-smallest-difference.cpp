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
        s1.insert(num3);


        auto item = s1.lower_bound(num3);
        auto item2 = s1.upper_bound(num3);

        if (item != s1.begin()) {
            item--;
            if ((num3 - *item) > num2 && (num3 - *item) < minans) {
                minans = num3 - *item;
            }
        }

        if (item2 != s1.end()) {
            item2++;

            if ((*item2 - num3) > num2 && (*item2 - num3) < minans) {
                minans = *item2 - num3;
            }
        }
    }

    if (minans == 2134567890) {
        cout << -1;
        return 0;
    }
    cout << minans;

    // 여기에 코드를 작성해주세요.
    return 0;
}