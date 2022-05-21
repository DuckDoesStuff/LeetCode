#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> umap;
    for(int i = 0; i < nums.size(); i++) {
        //if number target - nums[i] is in the umap which means we have found a pair
        //if not add nums[i] to the umap
        if(umap.find(target - nums[i]) != umap.end()) {
            ans.push_back(umap[target - nums[i]]);
            ans.push_back(i);
        }else {
            umap.insert(make_pair(nums[i], i));
        }
    }
    return ans;
}

int main() {
    vector<int> nums = { 2, 7, 9, 15 };

    vector<int> ans = twoSum(nums, 11);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}