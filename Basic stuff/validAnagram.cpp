#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool isAnagram(string s, string t) {
    map<char, int> mps, mpt;

    int n = s.length(), m = t.length();
    if(n != m) return false;
    for(int i = 0; i < n; i++) {
        mps[s[i]]++;
        mpt[t[i]]++;
    }

    return mpt == mps;
}

bool isAnagram2(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main() {
    string str1 = "anagram";
    string str2 = "nagraam";
    cout << isAnagram2(str1, str2); 
    
    return 0;
}