#include <iostream>
#include <queue>
#include <deque>

using namespace std;

double num1, num2, num3;

double Map[330][330];
double ansMap[330][330];

struct Node{
    int y;
    int x;
};


void init(){

}

void input(){
    cin >> num1 >> num2 >> num3;

    for(int n1 = 0; n1 < num1; n1++){
        for(int n2 = 0; n2 < num2; n2++){
            cin >> Map[n1][n2];
        }
    }

}

void solve(){
    int cnt = 0;
    int checky = num1;
    int checkx = num2;
    while(1){

        deque<int> q1;
        deque<Node> q2;
        for(int n1 = cnt; n1 < (num1 - cnt); n1++){
            q1.push_back(Map[n1][cnt]);
            q2.push_back({n1, cnt});
        }
        
        for(int n1 = cnt + 1; n1 < (num2 - cnt - 1); n1++){
            q1.push_back(Map[num1 - 1 - cnt][n1]);
            q2.push_back({num1 - 1 - cnt, n1});
        }

        for(int n1 = num1 - 1 - cnt; n1 >= cnt; n1--){
            q1.push_back(Map[n1][num2 - cnt - 1]);
            q2.push_back({n1, num2 - cnt - 1});
        }

        for(int n1 = num2 - 2 - cnt; n1 >= (1 + cnt); n1--){
            q1.push_back(Map[cnt][n1]);
            q2.push_back({cnt, n1});
        }

        cnt++;

        int len = q1.size();
        int mv = num3 % len;

        for(int n1 = mv; n1 < q2.size(); n1++){
            ansMap[q2[n1].y][q2[n1].x] = q1.front();
            q1.pop_front();
        }

        for(int n1 = 0; n1 < mv; n1++){
            ansMap[q2[n1].y][q2[n1].x] = q1.front();
            q1.pop_front();
        }

        checky = checky - 2;
        checkx = checkx - 2;


        if(checky <= 0 || checkx <= 0) break;
    }


    for(int n1 = 0; n1 < num1; n1++){
        for(int n2 = 0; n2 < num2; n2++){
            cout << ansMap[n1][n2] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}