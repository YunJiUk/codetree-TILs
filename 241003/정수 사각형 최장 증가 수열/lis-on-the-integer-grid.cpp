#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int arr[501][501];
int dp[501][501];
int n;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

vector<tuple<int,int,int>> v;
int ans;

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
            v.push_back(make_tuple(arr[i][j],i,j));
        }
    }
    sort(v.begin(),v.end());

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1;
        }
    }
    for(int i=0;i<(int) v.size();i++){
        int row, col;
        tie(ignore,row,col)=v[i];

        for(int j=0;j<4;j++){
            int nr=row+dr[j];
            int nc=col+dc[j];
            if(nr>=1 && nr<=n && nc>=1 && nc<=n && arr[row][col]<arr[nr][nc]){
                dp[nr][nc] = max(dp[nr][nc], dp[row][col]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}