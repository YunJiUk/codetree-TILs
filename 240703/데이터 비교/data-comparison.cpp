#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int n,m;
unordered_set<int> s1, s2;
vector<int> v1, v2;
int main() {
    cin >> n;
    for(int i = 0 ; i<n; i++){
        int t; cin >> t;
        v1.push_back(t);
        s1.insert(t);
    }

    cin >> m;
    for(int i = 0 ; i<m; i++){
        int t; cin >> t;
        v2.push_back(t);
        s2.insert(t);
    }

    for(int i = 0; i< v2.size(); i++){
        if(s1.find(v2[i]) == s1.end()) cout << 0 << " ";
        else cout << 1 << " ";
    }



    return 0;
}