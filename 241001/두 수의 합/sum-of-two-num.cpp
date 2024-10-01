#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> um;

int n,k,tmp,ans;

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>tmp;
        um[tmp]+=1;
    }
    for(auto tmp_um:um){
        if(k-tmp_um.first==tmp_um.first){
            ans+=(um[k-tmp_um.first]*(um[k-tmp_um.first]-1));
        }
        else ans+=um[k-tmp_um.first];
    }
    cout<<ans/2;
    return 0;
}