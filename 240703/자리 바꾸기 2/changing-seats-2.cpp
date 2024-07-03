#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node{
    int first;
    int second;
};

unordered_set<int> us1[100001];
int Map[100001];

vector<Node> v1;

int num1, num2, num3, num4;

void init(){

}

void input(){
    cin >> num1 >> num2;
    for(int n1 = 1; n1 <= num1; n1++){
        Map[n1] = n1;
        us1[n1].insert(n1);
    }

    for(int n1 = 0; n1 < num2; n1++){
        cin >> num3 >> num4;
        v1.push_back({num3, num4});
    }



}

void solve(){
    for(int n2 = 0; n2 < 3; n2++){
    for(int n1 = 0; n1< v1.size(); n1++){
        us1[Map[v1[n1].first]].insert(v1[n1].second);
        us1[Map[v1[n1].second]].insert(v1[n1].first);

        int swap = Map[v1[n1].first];
        Map[v1[n1].first] = Map[v1[n1].second];
        Map[v1[n1].second] = swap;
    }
    }
    for(int n1 = 1; n1 <= num1; n1++){
        cout << us1[n1].size() << endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();

    input();

    solve();

    return 0;
}