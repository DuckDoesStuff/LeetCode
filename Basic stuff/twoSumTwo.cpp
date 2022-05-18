#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;

    int left = 0, right = numbers.size() - 1;

    while(left < right) {
        int sum = numbers[left] + numbers[right];
        if(sum < target) left++;
        else if (sum > target) right--;
        else if (sum == target) {
            res.push_back(left + 1);
            res.push_back(right + 1);
            break;
        }
    }

    return res;
}

int binarySearch(vector<int>& numbers, int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right)/2;
        if(numbers[mid] > target) right = mid - 1;
        else if (numbers[mid] < target) left = mid + 1;
        else return mid;
    }
    return -1;
}

vector<int> twoSumBS(vector<int>& numbers, int target) {
    vector<int> res(2);

    for(int i = 0; i < numbers.size(); i++) {
        int index = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
        if(index != -1) {
            res[0] = i + 1;
            res[1] = index + 1;
            return res;
        }
    }
    return res;
}

int main() {
    vector<int> num = {2,7,11,15};
    int target = 9;

    vector<int> res = twoSumBS(num, target);

    cout << "[" << res[0] << ", " << res[1] << "]";

    return 0;
}