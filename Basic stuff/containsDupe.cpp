#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    map<int, int> mp;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(mp.count(nums[i]) != 0) return true;
        else mp.insert(make_pair(nums[i], i));
    }
    return false;
}

int main () {
    vector<int> nums = {1,2,3,4};

    cout << containsDuplicate(nums);

    return 0;
}