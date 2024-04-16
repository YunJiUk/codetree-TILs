#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
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
	int start;
	int to;
	int weight;
	int price;
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
vector<Node> bil[2200];
int visited[2200];
int record[2200][2200];
unordered_map <int, Node2> um1;

void dijkstra(int starting) {
	const int MAX_WEIGHT = 100;  // 가정: 최대 가중치는 100
	vector<list<pair<int, int>>> buckets(num2 * MAX_WEIGHT);
	int idx = 0;

	vector<int> distance(num2, INT_MAX);
	distance[starting] = 0;
	buckets[0].push_back({ starting, 0 });

	while (idx < buckets.size()) {
		while (buckets[idx].empty() && idx < buckets.size()) idx++;
		if (idx == buckets.size()) break;

		while (!buckets[idx].empty()) {
			int here = buckets[idx].front().first;
			int dist = buckets[idx].front().second;
			buckets[idx].pop_front();

			if (dist > distance[here]) continue;

			for (auto& edge : bil[here]) {
				int next = edge.to;
				int nextDist = dist + edge.weight;
				if (distance[next] > nextDist) {
					distance[next] = nextDist;
					buckets[nextDist].push_back({ next, nextDist });
				}
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

			int Far = record[realStart][Go];
			if (Far == 0 && realStart != Go) {
				Far = 2134567890;
			}
			um1[Id] = { realStart, Go, Far, Price };
		}

		else if (num4 == 400) {
			int min = -1;
			int minidx = -1;
			for (const auto& a1 : um1) {
				if (a1.second.price - a1.second.weight > min) {
					min = a1.second.price - a1.second.weight;
					minidx = a1.first;
				}

				else if (a1.second.price - a1.second.weight == min) {
					if (a1.first < minidx) {
						min = a1.second.price - a1.second.weight;
						minidx = a1.first;
					}
				}
			}

			if (min == -1) {
				cout << -1 << "\n";
			}
			else {
				cout << minidx << "\n";
				um1.erase(minidx);
			}
		}

		else if (num4 == 300) {
			int eridx;
			cin >> eridx;
			um1.erase(eridx);
		}

		else if (num4 == 500) {
			int chnum;
			cin >> chnum;
			realStart = chnum;


			if (dat[realStart] == 0) {
				dijkstra(realStart);

				for (int n1 = 0; n1 < num2; n1++) {
					record[n1][realStart] = visited[n1];
					record[realStart][n1] = visited[n1];
				}
				dat[realStart] = 1;
			}


			for (const auto& a1 : um1) {

				int Far = record[realStart][a1.second.to];
				if (Far == 0 && realStart != a1.second.to) {
					Far = 2134567890;
				}
				um1[a1.first] = { realStart, a1.second.to, Far, a1.second.price };
			}
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