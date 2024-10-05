#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int n, ans_block, ans_cnt;
bool visited[101][101];

struct pos{
    int row,col;
};

int dr[]={0,0,-1,1};
int dc[]={-1,1,0,0};

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j]==false){
                int now_num=arr[i][j],tmp_cnt=1;
                queue<pos> q;
                q.push({i,j});
                visited[i][j]=1;
                while(!q.empty()){
                    pos now = q.front();
                    q.pop();
                    for(int k =0;k<4;k++){
                        int nr = now.row+dr[k];
                        int nc = now.col+dc[k];
                        if(nr<=0 || nc<=0 || nr>n||nc>n) continue;
                        if(visited[nr][nc]) continue;
                        if(arr[nr][nc]!=now_num) continue;
                        q.push({nr,nc});
                        visited[nr][nc]=1;
                        tmp_cnt++;
                    }
                }
                if(tmp_cnt>=4) ans_block++;
                if(ans_cnt<tmp_cnt) ans_cnt=tmp_cnt;
            }
        }
    }

    cout<<ans_block<<" "<<ans_cnt;

    return 0;
}