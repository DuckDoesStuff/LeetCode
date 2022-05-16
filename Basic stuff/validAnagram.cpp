#include <iostream>
#include <string>
#include <map>

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

int main() {
    string str1 = "anagramc";
    string str2 = "nagraam";
    cout << isAnagram(str1, str2); 
    
    return 0;
}