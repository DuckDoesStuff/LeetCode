#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size(); j++) {
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long threeTarget = target - (long long)nums[i];
            int left = j + 1, right = nums.size() - 1;

            while(left < right) {
                long long threeSum = (long long)nums[left] + (long long)nums[right] + (long long)nums[j];
                if(threeSum == threeTarget) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left - 1] && left < right) left++;
                }
                else if (threeSum < threeTarget) left++;
                else right--;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {2,2,2,2,2};//-2, -1, 0, 0, 1, 2
    int target = 8;

    vector<vector<int>> res = fourSum(nums, target);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}