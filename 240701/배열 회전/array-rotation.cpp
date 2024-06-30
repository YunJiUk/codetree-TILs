#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int num1, num2, num3;
int Map[330][330];
int ansMap[330][330];

struct Node {
    int y;
    int x;
};

void init() {
    // 초기화 로직이 필요하면 여기에 작성
}

void input() {
    cin >> num1 >> num2 >> num3;

    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            cin >> Map[n1][n2];
        }
    }
}

void solve() {
    int cnt = 0;
    int checky = num1;
    int checkx = num2;

    while (true) {
        deque<int> q1;
        deque<Node> q2;

        // 각 layer의 테두리 요소들을 q1, q2에 삽입
        for (int n1 = cnt; n1 < num2 - cnt; n1++) {
            q1.push_back(Map[cnt][n1]);
            q2.push_back({cnt, n1});
        }

        for (int n1 = cnt + 1; n1 < num1 - cnt; n1++) {
            q1.push_back(Map[n1][num2 - cnt - 1]);
            q2.push_back({n1, num2 - cnt - 1});
        }

        for (int n1 = num2 - cnt - 2; n1 >= cnt; n1--) {
            q1.push_back(Map[num1 - cnt - 1][n1]);
            q2.push_back({num1 - cnt - 1, n1});
        }

        for (int n1 = num1 - cnt - 2; n1 > cnt; n1--) {
            q1.push_back(Map[n1][cnt]);
            q2.push_back({n1, cnt});
        }

        cnt++;

        int len = q1.size();
        int mv = num3 % len;

        // 회전한 값을 ansMap에 삽입
        for (int n1 = 0; n1 < len; n1++) {
            int idx = (n1 + mv) % len;
            ansMap[q2[n1].y][q2[n1].x] = q1[idx];
        }

        checky -= 2;
        checkx -= 2;

        if (checky <= 0 || checkx <= 0) break;
    }

    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            cout << ansMap[n1][n2] << " ";
        }
        cout << endl;
    }
}

int main() {
    init();
    input();
    solve();
    return 0;
}