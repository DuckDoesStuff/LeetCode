#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longesCommonUtil(string s1, string s2) {
    string res = "";
    int n1 = s1.length(), n2 = s2.length();
    for(int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
        if(s1[i] != s2[j])
            break;
        res.push_back(s1[i]);
    }
    return res;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1) return strs[0];
    string res = longesCommonUtil(strs[0], strs[1]);
    for(int i = 2; i < strs.size(); i++) {
        res = longesCommonUtil(res, strs[i]);
    }
    return res;
}

int main() {
    vector<string> strs = {"flower","flow","flight"};

    cout << longestCommonPrefix(strs);

    return 0;
}