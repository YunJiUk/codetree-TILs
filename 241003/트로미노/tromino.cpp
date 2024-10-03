#include <iostream>
#include <algorithm>
using namespace std;

int arr[201][201];
int n,m,ans=1;


int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //ㄱ
            if(i+1>n || j+1>n) continue;
            else{
                int a = arr[i][j], b=arr[i+1][j], c=arr[i][j+1], d=arr[i+1][j+1];
                ans=max(ans,max(a+b+c,max(a+b+d,max(a+c+d,b+c+d))));
            }
            if(i+2 >n) continue;
            else{
                int a=arr[i][j]+arr[i+1][j]+arr[i+2][j];
                ans=max(ans,a);
            }
            if(j+2>m) continue;
            else{
                int a = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                ans=max(ans,a);
            }
        }
    }

    cout<<ans;

    return 0;
}