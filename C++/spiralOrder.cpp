#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;

    int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
    while(left <= right && top <= bottom) {
        for(int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;

        if(left > right || top > bottom) break;
        
        for(int i = right; i >= left; i--) {
            res.push_back(matrix[bottom][i]);
        }
        bottom--;
        for(int i = bottom; i >= top; i--) {
            res.push_back(matrix[i][left]);
        }
        left++;
    }

    return res;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = spiralOrder(matrix);
    for(int i = 0; i < result.size(); i++) 
        cout << result[i] << " ";

    return 0;
}