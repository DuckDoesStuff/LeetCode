#include <iostream>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int res = -1;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 2) {
                
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> input = {{2,1,1},{1,1,0},{0,1,1}};

    cout << orangesRotting(input);

    return 0;
}