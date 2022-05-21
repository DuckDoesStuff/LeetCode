#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int result = 0;
    int l = 0;
    for(int r = 0; r < s.length(); r++) {
        while(mp.find(s[r]) != mp.end()) {
            mp.erase(s[l]);
            l++;
        }
        mp.insert(make_pair(s[r], r));
        result = max(result, r - l + 1);
    }
    return result;
}

int main() {
    string str = "abcabcbb";

    cout << lengthOfLongestSubstring(str);
    // map<char, int> mp;
    // for(int i = 0; i < str.length(); i++) {
    //     mp.insert(make_pair(str[i], i));
    // }
    // // mp.erase('e');
    // cout << endl;
    // // for(auto itr = mp.begin(); itr != mp.end(); itr++) {
    // //     cout << itr->first << " " << itr->second << endl;
    // // }
    // auto itr = mp.begin();
    // cout << itr->first << " " << itr->second << endl;
    // // cout << mp.size();

    return 0;
}