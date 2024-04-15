#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
	int y;
	int x;
	int out;
};

struct Node2 {
	int y;
	int x;
	int from;
	int superpass;
};


int num1, num2, num3;

int Map[75][75];
Node golem[1100];

int goy;
int gox;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dy1[4] = { 0, 0, 0, 1 };
int dx1[4] = { -1, 0, 1, 0 };

int dyd[5] = { -1, 0, 0, 0, 1 };
int dxd[5] = { 0, -1, 0, 1, 0 };

int dyl[5] = { -1, 0, 1, 1, 2 };
int dxl[5] = { -1, -2, -1, -2, -1 };

int dyr[5] = { -1, 0, 1, 1, 2 };
int dxr[5] = { 1, 2, 1, 2, 1 };

int realans = 0;

void godown() {
	while (1) {
		int breakflag = 0;
		goy++;
		for (int n2 = 0; n2 < 5; n2++) {
			int ny = goy + dyd[n2];
			int nx = gox + dxd[n2];

			if (ny < 0 || nx < 0 || ny >= num1 || nx >= num2) {
				breakflag = 1;
				break;
			}
			if (Map[ny][nx] != 0) {
				breakflag = 1;
				break;
			}
		}

		if (breakflag == 1) {
			goy--;
			break;
		}
	}
}

int goleft() {
	for (int n1 = 0; n1 < 5; n1++) {
		int ny = goy + dyl[n1];
		int nx = gox + dxl[n1];

		if (ny < 0 || nx < 0 || ny >= num1 || nx >= num2) {
			return -1;
		}

		if (Map[ny][nx] != 0)
			return -1;
	}

	goy = goy + 1;
	gox = gox - 1;

	return 0;
}


int goright() {
	for (int n1 = 0; n1 < 5; n1++) {
		int ny = goy + dyr[n1];
		int nx = gox + dxr[n1];

		if (ny < 0 || nx < 0 || ny >= num1 || nx >= num2) {
			return -1;
		}

		if (Map[ny][nx] != 0)
			return -1;
	}

	goy = goy + 1;
	gox = gox + 1;

	return 0;
}

void lout(int num) {
	golem[num].out--;
	if (golem[num].out == -1) {
		golem[num].out = 3;
	}
}

void rout(int num) {
	golem[num].out++;
	if (golem[num].out == 4) {
		golem[num].out = 0;
	}
}

int bfs(int y, int x) {
	int lowest = -1;
	int visited[75][75] = { 0, };
	queue<Node2> q1;
	q1.push({ y, x, Map[y][x] });
	visited[y][x] = 1;

	while (!q1.empty()) {
		Node2 front = q1.front();
		if (front.y > lowest) {
			lowest = front.y;
		}
		q1.pop();

		for (int n1 = 0; n1 < 4; n1++) {
			int ny = front.y + dy[n1];
			int nx = front.x + dx[n1];

			if (ny < 0 || nx < 0 || ny >= num1 || nx >= num2) continue;
			if (visited[ny][nx] != 0) continue;
			if (Map[ny][nx] == 0) continue;
			if (Map[ny][nx] != front.from && Map[ny][nx] != -1 * front.from && front.superpass != 1) continue;
			visited[ny][nx] = 1;

			if (Map[ny][nx] < 0) {
				q1.push({ ny, nx, Map[ny][nx] * -1, 1 });
			}
			q1.push({ ny, nx,  Map[ny][nx], 0 });
		}
	}

	return lowest - 2;
}

void init() {

}

void input() {
	cin >> num1 >> num2 >> num3;
	num1 = num1 + 3;

	for (int n1 = 0; n1 < num3; n1++) {
		cin >> golem[n1].x >> golem[n1].out;
		golem[n1].x--;
		golem[n1].y = 1;
	}
}

void solve() {
	for (int n1 = 0; n1 < num3; n1++) {
		int sry = 0;
		goy = golem[n1].y;
		gox = golem[n1].x;
		for (int n2 = 0; n2 < 4; n2++) {
			int ny = goy + dy1[n2];
			int nx = gox + dx1[n2];

			if (ny < 0 || nx < 0 || ny >= num1 || ny >= num2) {
				sry = 1;
				break;
			}
			if (Map[ny][nx] != 0) {
				sry = 1;
				break;
			}
		}



		godown();



		while (1) {
			int a = goleft();

			if (a == -1) {
				int b = goright();

				if (b == -1) {
					break;
				}
				else {
					rout(n1);
					godown();
				}
			}

			else {
				lout(n1);
				godown();
			}
		}

		if (goy <= 3) {
			memset(Map, 0, sizeof(Map));
			continue;
		}

		if (golem[n1].out == 0) {
			Map[goy - 1][gox] = -1 * (n1 + 1);
		}

		else if (golem[n1].out == 1) {
			Map[goy][gox + 1] = -1 * (n1 + 1);
		}

		else if (golem[n1].out == 2) {
			Map[goy + 1][gox] = -1 * (n1 + 1);
		}

		else if (golem[n1].out == 3) {
			Map[goy][gox - 1] = -1 * (n1 + 1);
		}

		for (int n2 = 0; n2 < 5; n2++) {
			int ny = goy + dyd[n2];
			int nx = gox + dxd[n2];

			if (Map[ny][nx] == 0) {
				Map[ny][nx] = n1 + 1;
			}
		}

		realans += bfs(goy, gox);
	}
}

int main() {
	init();

	input();

	solve();

	cout << realans;
}