#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num1, num2, num3;

int Map[330][330];
int ansMap[330][330];

void input() {
    cin >> num1 >> num2 >> num3;
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            cin >> Map[i][j];
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

    // If no rotations are needed, return
    if (rotations == 0) return;

    vector<int> temp;

    // Copy the layer into a temporary array in counterclockwise order
    for (int i = left; i <= right; i++) {
        temp.push_back(Map[top][i]);
    }
    for (int i = top + 1; i <= bottom; i++) {
        temp.push_back(Map[i][right]);
    }
    for (int i = right - 1; i >= left; i--) {
        temp.push_back(Map[bottom][i]);
    }
    for (int i = bottom - 1; i > top; i--) {
        temp.push_back(Map[i][left]);
    }

    // Rotate the temporary array counterclockwise
    rotate(temp.begin(), temp.begin() + rotations, temp.end());

    // Copy the rotated array back to the ansMap
    int index = 0;
    for (int i = left; i <= right; i++) {
        ansMap[top][i] = temp[index++];
    }
    for (int i = top + 1; i <= bottom; i++) {
        ansMap[i][right] = temp[index++];
    }
    for (int i = right - 1; i >= left; i--) {
        ansMap[bottom][i] = temp[index++];
    }
    for (int i = bottom - 1; i > top; i--) {
        ansMap[i][left] = temp[index++];
    }
}

void solve() {
    // Initialize ansMap with the original Map values
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            ansMap[i][j] = Map[i][j];
        }
    }

    int layers = min(num1, num2) / 2; // 각 레이어의 수

    for (int layer = 0; layer < layers; layer++) {
        rotateLayer(layer);
    }

    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            cout << ansMap[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}