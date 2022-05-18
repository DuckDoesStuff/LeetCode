#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        //isalnum() is used to check wheter a character is a number or a letter
        while(left < right && !isalnum(s[left]))
            left++;
        while(left < right && !isalnum(s[right]))
            right--;
        if(toupper(s[left]) != toupper(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    cout << isPalindrome(s);

    return 0;
}