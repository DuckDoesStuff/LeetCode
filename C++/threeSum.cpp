#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while(left < right) {
            if (nums[left] + nums[right] + nums[i] < 0) left++;
            else if (nums[left] + nums[right] + nums[i] > 0) right--;
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                while(left < right && nums[left] == nums[left - 1]) left++;
            }
        }
    }
    return ans; 
}

int main() {
    vector<int> nums = {0,0,0,0};//{-2,0,1,1,2};//{0,0,0,0}//-4 -1 -1 0 1 2 
    vector<vector<int>> ans;

    ans = threeSum(nums);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    nums = {-2,0,1,1,2};//{-1,0,1,2,-1,-4}
    ans = threeSum(nums);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }  

    return 0;      
}