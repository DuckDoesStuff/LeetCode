#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Too slow :((
vector<vector<int>> merge1(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < intervals.size(); i++) {
        int start1 = intervals[i][0], end1 = intervals[i][1];
        for(int j = i + 1; j < intervals.size(); j++) {
            int start = intervals[j][0], end = intervals[j][1];
            if(start <= end1) {
                end1 = max(end1, end);
                i++;
            }
        }
        res.push_back({start1, end1});
    }
    return res;
}

vector<vector<int>> merge2(vector<vector<int>> intervals) {
    
}

int main() {
    vector<vector<int>> intervals = 
    {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    //{{1,4},{2,3},{5,6}};
    //{{0,4},{1,4}};
    //{{1,10},{10,20},{2,8}};
    //{{1,4},{0,0}};

    vector<vector<int>> res = merge1(intervals);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}