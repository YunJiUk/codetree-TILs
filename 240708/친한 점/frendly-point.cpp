#include <iostream>
#include <set>

using namespace std;

int num1, num2, num3, num4;

struct Node {
    int y;
    int x;

    bool operator <(Node right) const {
        if (y < right.y) return true;
        if (y == right.y) {
            if (x < right.x) return true;
        }

        return false;
    }
};

set<Node> s1;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> num1 >> num2;

    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num3 >> num4;
        s1.insert({ num3, num4 });

    }

    
    for (int n1 = 0; n1 < num2; n1++) {
        cin >> num3 >> num4;




        if (s1.lower_bound({ num3, num4 }) != s1.end()) {

            Node nod1 = *s1.lower_bound({ num3, num4 });
            cout << nod1.y << " " << nod1.x << endl;
        }

        else {
            cout << "-1 -1" << endl;
        }
    }

    return 0;
}