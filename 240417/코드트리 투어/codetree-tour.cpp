#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

struct Node {
	int start;
	int to;
	int weight;

	bool operator <(Node right) const {
		if (weight > right.weight) return true;
		return false;
	}
};

struct Node2 {
	int id;
	int start;
	int to;
	int weight;
	int price;

	bool operator <(Node2 right) const {
		if (price - weight < right.price - right.weight) return true;
		return false;
	}
};

int realStart = 0;
int num1, num2, num3;
int num4;
int asd;
int Start;
int To;
int Weight;

int Id;
int Price;
int Go;

int dat[2200];
int datId[2200];
vector<Node> bil[2200];
int visited[2200];
int record[2200][2200];
unordered_map <int, Node2> um1;
priority_queue<Node2> pq1;


void dijkstra(int starting) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1;
	fill(visited, visited + num2, INT_MAX);
	visited[starting] = 0;
	q1.push({ 0, starting });

	while (!q1.empty()) {
		int dist = q1.top().first;
		int here = q1.top().second;
		q1.pop();

		// 이미 방문한 노드와 거리가 더 긴 경우 스킵
		if (dist > visited[here]) continue;

		for (auto& edge : bil[here]) {
			int next = edge.to;
			int nextDist = dist + edge.weight;
			if (visited[next] > nextDist) {
				visited[next] = nextDist;
				q1.push({ nextDist, next });
			}
		}
	}
}



void init() {

}

void input() {
	cin >> num1;
	cin >> asd;
	cin >> num2 >> num3;


	for (int n1 = 0; n1 < num3; n1++) {
		cin >> Start >> To >> Weight;
		bil[Start].push_back({ Start, To, Weight });
		if (Start != To) {
			bil[To].push_back({ To, Start, Weight });
		}
	}

	dijkstra(realStart);
	dat[0] = 1;
	

	for (int n1 = 0; n1 < num2; n1++) {
		record[n1][realStart] = visited[n1];
		record[realStart][n1] = visited[n1];
	}

	for (int n1 = 0; n1 < num1 - 1; n1++) {
		cin >> num4;
		if (num4 == 200) {
			cin >> Id >> Price >> Go;
			datId[Id] = 1;

			int Far = record[realStart][Go];
			if (Far == 0 && realStart != Go) {
				Far = 2134567890;
			}

			pq1.push({ Id, realStart, Go, Far, Price });
		}

		else if (num4 == 400) {
			int min = -1;
			int minidx = -1;

			if (datId[pq1.top().id] == 0) cout << -1 << "\n";

			if (pq1.top().price - pq1.top().weight < 0) {
				cout << -1 << "\n";
			}

			else {
				cout << pq1.top().id << "\n";
				pq1.pop();
			}
		}

		else if (num4 == 300) {
			int eridx;
			cin >> eridx;
			datId[eridx] = 0;
		}

		else if (num4 == 500) {
			int chnum;
			cin >> chnum;
			realStart = chnum;
			priority_queue<Node2> pq2;

			if (dat[realStart] == 0) {
				dijkstra(realStart);

				for (int n1 = 0; n1 < num2; n1++) {
					record[n1][realStart] = visited[n1];
					record[realStart][n1] = visited[n1];
				}
				dat[realStart] = 1;
			}

			while (!pq1.empty()) {
				Node2 top = pq1.top();

				int Far = record[realStart][top.to];
				if (Far == 0 && realStart != top.to) {
					Far = 2134567890;
				}
				pq2.push({ top.id , top.start, top.to, Far, top.price });
				pq1.pop();
			}


			pq1 = pq2;
		}
	}




}

void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("input2.txt", "r", stdin);

	init();

	input();

	solve();
}