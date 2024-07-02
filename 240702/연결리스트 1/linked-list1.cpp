#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str1, str2;
int num1, num2;

struct Node {
    string data;
    Node* prev;
    Node* next;

    Node(string data) : data(data), prev(nullptr), next(nullptr) {};
};

void connect(Node* front, Node* back) {
    if (nullptr != front) front->next = back;
    if (nullptr != back) back->prev = front;
}

void insert(Node* front, Node* back) {
    connect(back, front->next);
    connect(front, back);
}

void print(Node* tar) {
    string n = "(Null)";

    if (tar->prev == nullptr) cout << n << " ";
    else cout << tar->prev->data << " ";

    cout << tar->data << " ";

    if (tar->next == nullptr) cout << n << "\n";
    else cout << tar->next->data << "\n";
}

void init() {

}

void input() {
    cin >> str1;
    cin >> num1;

    Node* cur = new Node(str1);


    for (int n1 = 0; n1 < num1; n1++) {
        cin >> num2;
        if (num2 == 1) {
            cin >> str2;
            Node* cur2 = new Node(str2);
            insert(cur2, cur);
        }
        else if (num2 == 2) {
            cin >> str2;
            Node* cur2 = new Node(str2);
            insert(cur, cur2);
        }
        else if (num2 == 3) {
            if (cur->prev != nullptr) {
                cur = cur->prev;
            }
        }
        else if (num2 == 4) {
            if (cur->next != nullptr) {
                cur = cur->next;
            }
        }

        print(cur);
    }

    
}

void solve() {

}

int main() {
    init();

    input();

    solve();
}