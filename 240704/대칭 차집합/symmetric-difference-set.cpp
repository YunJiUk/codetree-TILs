#include <iostream>
#include <unordered_set>

#define MAX_NUM 200000

using namespace std;

// 변수 선언
int n, m;
int A[MAX_NUM];
int B[MAX_NUM];
int ans;

unordered_set<int> s;

int main() {
    // 입력:
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < m; i++)
        cin >> B[i];
    
    ans = n + m;
    
    // 수열 A의 원소를 전부 HashSet에 넣어줍니다.
    for(int i = 0; i < n; i++)
        s.insert(A[i]);
    
    // 수열 B의 각 원소가 첫 번째 수열에 들어있는지를 확인합니다.
    for(int i = 0; i < m; i++) {
        // 만약 들어있다면 수열 A와 수열 B에 모두 있는 값입니다.
        // 이는 대칭 차집합의 원소가 아니므로 정답의 개수에서 지워줍니다.
        if(s.find(B[i]) != s.end())
            ans -= 2;
    }

    // 대칭 차집합의 원소의 개수를 출력합니다.
    cout << ans;

    return 0;
}