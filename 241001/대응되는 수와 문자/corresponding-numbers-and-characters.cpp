#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> um;


int n, m;
string str;

int main() {
    cin>>n>>m;
    // 여기에 코드를 작성해주세요.
    for(int i=1;i<=n;i++){
        cin>>str;
        um[str]=to_string(i);
        um[to_string(i)]=str;
    }
    for(int i=1;i<=m;i++){
        cin>>str;
        cout<<um[str]<<'\n';
    }


    return 0;
}