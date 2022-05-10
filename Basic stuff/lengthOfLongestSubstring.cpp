#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int result = 0;
    int l = 0;
    for(int r = 0; r < s.length(); r++) {
        //nếu s[r] trùng với ký tự mới vừa add vào thì sẽ dời l sao cho s[r] không còn trong substring
        if(mp.find(s[r]) != mp.end()) l = max(r, mp[s[r]] + 1); 
        mp.insert(make_pair(s[r], r));
        result = max(result , r - l + 1);
    }
    return result;
}

int main() {
    string str = "pwwkew";

    cout << lengthOfLongestSubstring(str);
    map<char, int> mp;
    // for(int i = 0; i < str.length(); i++) {
    //     mp.insert(make_pair(str[i], i));
    // }
    // // mp.erase('e');
    // cout << endl;
    // for(auto itr = mp.begin(); itr != mp.end(); itr++) {
    //     cout << itr->first << " " << itr->second << endl;
    // }
    // // cout << mp[str[1]];
    // // auto itr = mp.find(str[2]);
    // // cout << itr->first << " " << itr->second << endl;
    // cout << mp.size();

    return 0;
}