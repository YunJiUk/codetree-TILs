#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,ans=0;
    cin>>n;

    string str;

    for(int i=0;i<n;i++){
        cin>>str;
        um[str]+=1;
        if(um[str]>ans) ans=um[str];
    }
    cout<<ans;
    return 0;
}