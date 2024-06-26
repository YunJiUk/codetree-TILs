#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num1, num2;
int maxcnt = -2134567890;

struct Node {
    int price;
    int halfprice;
    int deliver;
};

vector<Node> box;
vector<Node> box2;

bool sortFunc(Node left, Node right) {
    if ((left.price + left.deliver) < (right.price + right.deliver)) return true;
    return false;
}

void init() {

}

void input() {
    cin >> num1 >> num2;
    box.resize(num1);
    box2.resize(num1);

    for (int n1 = 0; n1 < num1; n1++) {
        cin >> box[n1].price >> box[n1].deliver;
        box[n1].halfprice = box[n1].price / 2;
    }
}

void solve() {
    sort(box.begin(), box.end(), sortFunc);

    for (int n1 = 0; n1 < num1; n1++) {
        int cnt = 0;
        int startseed = box[n1].halfprice + box[n1].deliver;
        if (startseed > num2) continue;

        cnt++;

        for (int n2 = 0; n2 < num1; n2++) {
            if (n2 == n1) continue;
            startseed += box[n2].price + box[n2].deliver;
            if (startseed < num2) {
                cnt++;
            }
            else {
                if (cnt > maxcnt) {
                    maxcnt = cnt;
                }
                break;
            }
        }
    }
}

int main() {
    init();

    input();

    solve();

    cout << maxcnt;

    return 0;
}