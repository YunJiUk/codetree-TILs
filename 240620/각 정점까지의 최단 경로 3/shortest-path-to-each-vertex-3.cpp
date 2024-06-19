#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int num1, num2, num3, num4, num5;
int visited[101];
int realans = 2134567890;

struct Node {
    int tar;
    int weight;
    int cnt;

    bool operator <(Node right) const {
        if (weight > right.weight) return true;
        return false;
    }
};
vector<vector<Node>> v1;

void dijkstra() {
    priority_queue<Node> q1;

    
    for (int n1 = 0; n1 < 101; n1++) {
        visited[n1] = 2134567890;
    }

    visited[1] = 0;

    for (int n1 = 0; n1 < v1[1].size(); n1++) {
        q1.push({ v1[1][n1].tar, v1[1][n1].weight, 1});
        if (visited[v1[1][n1].tar] > v1[1][n1].weight) {
            visited[v1[1][n1].tar] = v1[1][n1].weight;
        }
    }

    while (!q1.empty()) {
        Node top = q1.top();
        q1.pop();
        if (top.cnt == num1) {
            if (realans > top.weight) {
                realans = top.weight;
            }
            continue;
        }

        for (int n1 = 0; n1 < v1[top.tar].size(); n1++) {
            int n_weight = top.weight + v1[top.tar][n1].weight;
            if (visited[v1[top.tar][n1].tar] <= n_weight) continue;
            visited[v1[top.tar][n1].tar] = n_weight;
            q1.push({ v1[top.tar][n1].tar , n_weight, top.cnt + 1});
        }
    }
}

void init() {

}

void input() {
    cin >> num1 >> num2;
    v1.resize(num1 + 1);

    for (int n1 = 0; n1 < num2; n1++) {
        cin >> num3 >> num4 >> num5;

        v1[num3].push_back({ num4, num5 });
    }
}

void solve() {
    dijkstra();

    for (int n1 = 2; n1 <= num1; n1++) {
        if (visited[n1] == 2134567890) {
            cout << -1 << endl;
        }
        else cout << visited[n1] << endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}