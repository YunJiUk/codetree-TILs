#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int num1, num2, num3;

unordered_map<int, int> um1;

struct Node{
    int num;
    int cnt;
};

vector<Node> v1;

bool sortFunc(Node left, Node right){
    if(left.cnt > right.cnt) return true;
    else if(left.cnt == right.cnt){
        if(left.num > right.num) return true;
    }
    return false;
}

void init(){

}

void input(){
    cin >> num1 >> num2;
    for(int n1 = 0; n1 < num1; n1++){
        cin >> num3;
        um1[num3]++;
    }


    for(auto item : um1){
        v1.push_back({item.first, item.second});
    }
}

void solve(){
    sort(v1.begin(), v1.end(), sortFunc);

    for(int n1 = 0; n1 < num2; n1++){
        cout << v1[n1].num << " ";
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    
    init();

    input();

    solve();


    return 0;
}