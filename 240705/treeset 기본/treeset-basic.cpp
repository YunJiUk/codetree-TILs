#include <iostream>
#include <set>
#include <string>

using namespace std;

int num1, num2;
string str1;

set<int> s1;

void init() {

}

void input() {
    cin >> num1;
    for (int n1 = 0; n1 < num1; n1++) {
        cin >> str1;


        if (str1 == "add") {
            cin >> num2;
            s1.insert(num2);
        }

        else if (str1 == "remove") {
            cin >> num2;
            s1.erase(num2);
        }

        else if (str1 == "largest") {
            if(s1.rbegin() != s1.rend()){
                cout << *s1.rbegin() << endl;
            }
            else{
                cout << "None" << endl;
            }
        }

        else if (str1 == "smallest") {

            if(s1.find(*s1.begin()) != s1.end()){
                cout << *s1.begin() << endl;
            }
            else{
                cout << "None" << endl;
            }
        }

        else if (str1 == "find") {
            cin >> num2;
            if (s1.find(num2) != s1.end()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }

        else if (str1 == "lower_bound") {
            cin >> num2;
            if(s1.lower_bound(num2) != s1.end()){
                cout << *s1.lower_bound(num2) << endl;
            }
            else{
                cout << "None" << endl;
            }
        }

        else if (str1 == "upper_bound") {
            cin >> num2;
            if(s1.upper_bound(num2) != s1.end()){
                cout << *s1.upper_bound(num2) << endl;
            }
            else{
                cout << "None" << endl;
            }
        }
    }
}

void solve() {

}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    input();

    solve();

    return 0;
}