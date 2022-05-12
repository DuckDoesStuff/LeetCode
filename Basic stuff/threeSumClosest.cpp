#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int result = 9999;
    sort(nums.begin(), nums.end());

    int a, b, c;
    
    for(int i = 0; i < nums.size(); i++) {
        int left = i + 1, right = nums.size() - 1;
        int sum;
        a = nums[i], b = nums[left], c = nums[right];
        while(left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if(sum < target) left++;
            else if(sum > target) right--;
            if(abs(sum - target) < abs(result - target)) result = sum;
            if (sum == target) break;
        }
    }

    return result;
}

int main() {
    vector<int> nums;
    nums = {0, 1, 2};
    int target = 3;

    cout << threeSumClosest(nums, target);
    return 0;
}