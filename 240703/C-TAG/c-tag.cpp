#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int num1, num2;
int ans = 0;

vector<string> v1;
vector<string> v2;

string str1;

unordered_set<string> us1;
int check[3];
string checkstring;
string checkstring2;

void dfs(int level, int idx) {
    if (level == 3) {
        for (int n1 = 0; n1 < v1.size(); n1++) {
            for (int n2 = 0; n2 < 3; n2++) {
                checkstring[n2] = v1[n1][check[n2]];
                
            }

            us1.insert(checkstring);
        }


        for (int n1 = 0; n1 < v1.size(); n1++) {
            for (int n2 = 0; n2 < 3; n2++) {
                checkstring2[n2] = v2[n1][check[n2]];
            }

            if (us1.find(checkstring2) != us1.end()) {
                us1.clear();
                return;
            }
        }

        us1.clear();
        ans++;
        return;
    }

    for (int n1 = idx; n1 < num2; n1++) {
        check[level] = n1;
        dfs(level + 1, n1 + 1);
    }
}


void dfs2(int level, int idx) {
    if (level == 3) {
        int checkAns = 1;
        for (int n1 = 0; n1 < v2.size(); n1++) {
            for (int n2 = 0; n2 < 3; n2++) {
                checkstring[n2] = v2[n1][check[n2]];
            }

            if (us1.find(checkstring) != us1.end()) {
                return;
            }
        }

        ans++;
        return;
    }

    for (int n1 = idx; n1 < num2; n1++) {
        check[level] = n1;
        dfs2(level + 1, n1 + 1);
    }
}

void init() {

}

void input() {
    cin >> num1 >> num2;
    for (int n1 = 0; n1 < num1; n1++) {
        cin >> str1;
        v1.push_back(str1);
    }

    for (int n2 = 0; n2 < num1; n2++) {
        cin >> str1;
        v2.push_back(str1);
    }
}

void solve() {
    checkstring.resize(3);
    checkstring2.resize(3);
    dfs(0, 0);

    cout << ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}