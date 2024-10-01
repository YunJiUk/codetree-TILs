#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k,v;
    cin>>n;
    string cmd;
    for(int i=0;i<n;i++){
        cin>>cmd;
        if(cmd=="add"){
            cin>>k>>v;
            um[k]=v;
        }
        else if(cmd=="remove"){
            cin>>k;
            um.erase(k);
        }
        else{
            cin>>k;
            if(um.find(k)!=um.end()){
                cout<<um[k]<<'\n';
            }
            else{
                cout<<"None\n";
            }
        }
    }
    return 0;
}