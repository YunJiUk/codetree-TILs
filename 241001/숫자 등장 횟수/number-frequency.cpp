#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;
int n,m,k;

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k;
        um[k]+=1;
    }
    for(int i=0;i<m;i++){
        cin>>k;
        cout<<um[k]<<" ";
    }
    return 0;
}