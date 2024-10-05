#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int n,m;
struct pos{
    int row, col;
};
bool visited[101][101];
int dr[]={1,0};
int dc[]={0,1};

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    queue<pos> q;
    q.push({1,1});
    visited[1][1]=1;

    while(!q.empty()){
        pos now = q.front();
        q.pop();
        for(int i=0;i<2;i++){
            int nr=dr[i]+now.row;
            int nc=dc[i]+now.col;
            if(nr==n&&nc==m){
                cout<<1;
                return 0;
            }
            if(nr>n || nc>m) continue;
            if(visited[nr][nc]) continue;
            if(!arr[nr][nc]) continue;
            q.push({nr,nc});
            visited[nr][nc]=1;
        }
    }
    cout<<0;
    return 0;
}