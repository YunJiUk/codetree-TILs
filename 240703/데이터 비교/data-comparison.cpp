#include <iostream>
#include <unordered_set>

#define MAX_NUM 100000

using namespace std;

// 변수 선언
int n, m;
int arr1[MAX_NUM];
int arr2[MAX_NUM];

unordered_set<int> set1;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    
    // 첫 번째 수열의 원소를 전부 HashSet에 넣어줍니다.
    for(int i = 0; i < n; i++)
        set1.insert(arr1[i]);
    
    // 두 번째 수열의 각 원소가 첫 번째 수열에 들어있는지를 확인합니다.
    for(int i = 0; i < m; i++) {
        // 찾지 못했다면 0을 출력합니다.
        if(set1.find(arr2[i]) == set1.end())
            cout << 0 << " ";
        // 찾았다면 1을 출력합니다.
        else
            cout << 1 << " ";
    }

    return 0;
}