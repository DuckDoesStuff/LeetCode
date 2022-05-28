#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool keyCompare(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int res = 1, n = envelopes.size();
        //sort by increasing width, if same width sort by decreasing height
        sort(envelopes.begin(), envelopes.end(), keyCompare);

        vector<int> ele = envelopes[0];
        for(int i = 1; i < n; i++) {
            vector<int> ele_next = envelopes[i];
            if (ele[0] < ele_next[0] && ele[1] < ele_next[1]) {
                    res++;
                    ele = envelopes[i];
                }
        }

        return res;
    }
};

int main() {
    //{1,2} {2,3} {3,5} {3,4} {4,5} {5,6} {5,5} {6,7} {7,8}
    //{4,5}, {6,7}, {2,3}
    vector<vector<int>> envelopes = {{1,2}, {2,3}, {3,5}, {3,4}, {4,5}, {5,6}, {5,5}, {6,7}, {7,8}};//{{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    cout << Solution().maxEnvelopes(envelopes);
    return 0;
}