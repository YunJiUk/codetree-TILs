#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string str1;

char ans;

unordered_map<char, int> um1;

struct Node{
    int num;
    char c1;
};

vector<Node> v1;


void init(){

}

void input(){
    cin >> str1;

    for(int n1 = 0; n1 < str1.length(); n1++){
        um1[str1[n1]]++;
    }

    for(int n1 = 0; n1 < str1.length(); n1++){
        if(um1[str1[n1]] == 1) {
            cout << str1[n1]; 
            return;
        }
    }


    cout << "None";

}

void solve(){

}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}