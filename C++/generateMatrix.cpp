#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res;
    int num = 1;
    int startRow = 0, startCol = 0, endRow = n - 1, endCol = n - 1;

    int** matr = new int*[n];
    for(int i = 0; i < n; i++) {
        matr[i] = new int[n];
    }

    while(startRow <= endRow && startCol <= endCol) {
        for(int i = startCol; i <= endCol; i++) {
            matr[startRow][i] = num;
            num++;
        }
        startRow++;
        for(int i = startRow; i <= endRow; i++) {
            matr[i][endCol] = num;
            num++;
        }
        endCol--;

        if(startRow <= endRow) {
            for(int i = endCol; i >= startCol; i--) {
                matr[endRow][i] = num;
                num++;
            }
            endRow--;
        }

        if(startCol <= endCol) {
            for(int i = endRow; i >= startRow; i--) {
                matr[i][startCol] = num;
                num++;
            }
            startCol++;
        }
    }

    for(int i = 0; i < n; i++) {
        vector<int> t;
        for(int j = 0; j < n; j++) {
            t.push_back(matr[i][j]);
        }
        res.push_back(t);
    }

    return res;
}

int main() {
    int n = 3;

    vector<vector<int>> matr = generateMatrix(n);

    for(int i = 0; i < matr.size(); i++) {
        for(int j = 0; j < matr[i].size(); j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}