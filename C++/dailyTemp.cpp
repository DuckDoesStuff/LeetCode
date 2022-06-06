#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //TLE
        vector<int> res;
        int n = temperatures.size();
        for(int i = 0; i < n - 1; i++) {
            int cnt = 1, j = i + 1;
            while(j < n && temperatures[i] >= temperatures[j]) {
                cnt++;
                j++;
            }
            if(j >= n) cnt = 0;
            res.push_back(cnt);
        }
        res.push_back(0);
        return res;
    }
    vector<int> dailyTemperatures2(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);//init vector with n elements and value 0
        stack<pair<int, int>> stk;  //{temp, idx}
        for(int i = 0; i < n; i++) {
            //keep removing the top of the stack if it is < than current temp
            //also assign result as the difference between indxes
            while(!stk.empty() && stk.top().first < temperatures[i]) {
                pair<int, int> s = stk.top();
                stk.pop();
                res[s.second] = i - s.second;
            }
            stk.push({temperatures[i], i});
            
        }
        return res;
    }
};

int main() {
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> res = Solution().dailyTemperatures2(temp);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}