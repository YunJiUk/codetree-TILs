#include <iostream>
#include <vector>

using namespace std;

int num1, num2, num3;

int Map[550][550];
int ansMap[550][550];

void init() {
    // 필요시 초기화 코드를 여기에 작성
}

void input() {
    cin >> num1 >> num2 >> num3;
    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            cin >> Map[n1][n2];
        }
    }
}

void rotateLayer(int layer) {
    int top = layer;
    int bottom = num1 - layer - 1;
    int left = layer;
    int right = num2 - layer - 1;

    // Calculate the perimeter of the current layer
    int perimeter = 2 * (bottom - top + right - left);

    // Calculate effective rotations
    int rotations = num3 % perimeter;
    if (rotations == 0) return;

    vector<int> temp(perimeter);
    int index = 0;

    // Copy the layer into a temporary array
    for (int i = left; i <= right; i++) {
        temp[index++] = Map[top][i];
    }
    for (int i = top + 1; i <= bottom; i++) {
        temp[index++] = Map[i][right];
    }
    for (int i = right - 1; i >= left; i--) {
        temp[index++] = Map[bottom][i];
    }
    for (int i = bottom - 1; i > top; i--) {
        temp[index++] = Map[i][left];
    }

    // Rotate the temporary array counterclockwise
    vector<int> rotated(perimeter);
    for (int i = 0; i < perimeter; i++) {
        rotated[(i - rotations + perimeter) % perimeter] = temp[i];
    }

    // Copy the rotated array back to the ansMap
    index = 0;
    for (int i = left; i <= right; i++) {
        ansMap[top][i] = rotated[index++];
    }
    for (int i = top + 1; i <= bottom; i++) {
        ansMap[i][right] = rotated[index++];
    }
    for (int i = right - 1; i >= left; i--) {
        ansMap[bottom][i] = rotated[index++];
    }
    for (int i = bottom - 1; i > top; i--) {
        ansMap[i][left] = rotated[index++];
    }
}

void solve() {
    // Initialize ansMap with the original Map values
    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            ansMap[n1][n2] = Map[n1][n2];
        }
    }

    int layers = min(num1, num2) / 2; // 각 레이어의 수

    for (int layer = 0; layer < layers; layer++) {
        rotateLayer(layer);
    }

    for (int n1 = 0; n1 < num1; n1++) {
        for (int n2 = 0; n2 < num2; n2++) {
            cout << ansMap[n1][n2] << " ";
        }
        cout << endl;
    }
}

int main() {
    init();
    input();
    solve();
    return 0;
}