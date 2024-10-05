#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m,ans;
vector<int> line[1001];
bool visited[1001];

int main() {
    // 여기에 코드를 작성해주세요.

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int from, to;
        cin>>from>>to;
        line[from].push_back(to);
        line[to].push_back(from);
    }
    visited[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<line[now].size();i++){
            int nxt = line[now][i];
            if(visited[nxt]) continue;
            q.push(nxt);
            visited[nxt]=1;
            ans++;
        }
    }
    cout<<ans;

    return 0;
}