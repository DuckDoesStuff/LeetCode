#include <iostream>
#include <vector>

using namespace std;

//doesnt run on leetcode and idk why :(
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int left = 0, right = nums.size() - 1, mid;

    while(left <= right) {
        mid = (left + right)/2;
        if(nums[mid] < target) {
            left = mid + 1;
        }else if (nums[mid] > target) {
            right = mid - 1;
        }else {
            int start = mid, end = mid;
            while(nums[start] == target) start--;
            start++;
            while(nums[end] == target) end++;
            end--;

            res[0] = start, res[1] = end;
            break;
        }
    }

    return res;
}

int findStart(vector<int> nums, int n, int target) {
    int left = 0, right = n - 1;
    int start = -1;
    while(left <= right) {
        int mid = (left+right)/2;
        if(nums[mid] == target) {
            start = mid;
            right = mid - 1;//lowering the right index to find the lower start
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else left = mid + 1;
    }
    return start;
}

int findEnd(vector<int> nums, int n, int target) {
    int left = 0, right = n - 1;
    int end = -1;
    while(left <= right) {
        int mid = (left+right)/2;
        if(nums[mid] == target) {
            end = mid;
            left = mid + 1;//increasing the left index to find the higher end index
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else left = mid + 1;
    }
    return end;
}

vector<int> searchRange2(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> res = {findStart(nums, n, target), findEnd(nums, n, target)};
    return res;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> result = searchRange2(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]";

    return 0;
}