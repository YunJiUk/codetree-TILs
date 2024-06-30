#include <iostream>
#include <deque>

using namespace std;

int num1, num2, num3;

int Map[330][330];
int ansMap[330][330];

struct Node {
    int y, x;
};

void init() {
    // 필요시 초기화 코드를 여기에 작성
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
    int layers = min(num1, num2) / 2; // 각 레이어의 수

    for (int layer = 0; layer < layers; layer++) {
        deque<int> q1;
        deque<Node> q2;

        // 상단
        for (int i = layer; i < num2 - layer; i++) {
            q1.push_back(Map[layer][i]);
            q2.push_back({layer, i});
        }
        // 우측
        for (int i = layer + 1; i < num1 - layer; i++) {
            q1.push_back(Map[i][num2 - layer - 1]);
            q2.push_back({i, num2 - layer - 1});
        }
        // 하단
        for (int i = num2 - layer - 2; i >= layer; i--) {
            q1.push_back(Map[num1 - layer - 1][i]);
            q2.push_back({num1 - layer - 1, i});
        }
        // 좌측
        for (int i = num1 - layer - 2; i > layer; i--) {
            q1.push_back(Map[i][layer]);
            q2.push_back({i, layer});
        }

        int len = q1.size();
        int mv = num3 % len;

        // 회전한 값을 ansMap에 삽입
        for (int i = 0; i < len; i++) {
            int idx = (i + mv) % len;
            ansMap[q2[i].y][q2[i].x] = q1[idx];
        }
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