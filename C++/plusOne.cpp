#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    int i = digits.size() - 1;
    do {
        if(i == 0) {
            if((digits[0] + 1) % 10 == 0) {
                digits[0] = 1;
                digits.push_back(0);
            }else digits[0] += 1;
            break;
        }
        if((digits[i] + 1) % 10 == 0) {
            carry = 1;
            digits[i] = 0;
        }else {
            digits[i] += carry;
            carry = 0;
        }
        i--;
    }
    while(carry);
    return digits;
}

int main() {
    vector<int> nums = {9,8,9};
    nums = plusOne(nums);

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}