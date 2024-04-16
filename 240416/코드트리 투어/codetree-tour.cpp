#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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


vector<Node> bil[2200];
int visited[2200];
int record[2200][2200];
unordered_map <int, Node2> um1;

void dijkstra(int starting) {
	for (int n1 = 0; n1 < num2; n1++) {
		visited[n1] = 2134567890;
	}

	priority_queue<Node> q1;
	visited[starting] = 0;
	record[starting][starting] = 0;
	for (int n1 = 0; n1 < bil[starting].size(); n1++) {
		if (visited[bil[starting][n1].to] <= bil[starting][n1].weight) continue;
		q1.push({ bil[starting][n1] });
		visited[bil[starting][n1].to] = bil[starting][n1].weight;
		record[starting][bil[starting][n1].to] = bil[starting][n1].weight;
		record[bil[starting][n1].to][starting] = bil[starting][n1].weight;
	}

	while (!q1.empty()) {
		Node top = q1.top();
		q1.pop();

		for (int n1 = 0; n1 < bil[top.to].size(); n1++) {
			int checking = bil[top.to][n1].weight + visited[top.to];
			if (visited[bil[top.to][n1].to] <= checking) continue;
			q1.push({ top.to, bil[top.to][n1].to, checking });
			visited[bil[top.to][n1].to] = checking;
			record[starting][bil[top.to][n1].to] = checking;
			record[bil[top.to][n1].to][starting] = checking;
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

	for (int n1 = 0; n1 < num1 - 1; n1++) {
		cin >> num4;
		if (num4 == 200) {
			cin >> Id >> Price >> Go;
			if (record[realStart][Go] == 0) {
				dijkstra(realStart);
			}
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

			for (auto& a1 : um1) {
				a1.second.start = chnum;
				if (record[realStart][a1.second.to] == 0) {
					dijkstra(realStart);
				}
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

	//freopen("input1.txt", "r", stdin);

	init();

	input();

	solve();
}