#include <iostream>
#include <vector>
#include <set>

using namespace std;

int num1, num2, num3;



struct sortset {
    bool operator()(int left, int right) const{
        if (left > right) return true;
        return false;
    }
};

set<int, sortset> s1;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> num1 >> num2;

    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num3;

        s1.insert(num3);
    }

    int cnt = 0;
    for (auto item : s1) {
        cnt++;
        cout << item << " ";

        if (cnt == num2) {
            break;
        }
    }

    return 0;
}