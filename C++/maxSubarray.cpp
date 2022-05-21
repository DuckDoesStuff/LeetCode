#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_so_far = INT_MIN, curr_max = 0;

    for(int i = 0; i < nums.size(); i++) {
        curr_max += nums[i];
        max_so_far = max(curr_max, max_so_far);
        if(curr_max < 0) curr_max = 0;
    }

    return max_so_far;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);

    return 0;
}