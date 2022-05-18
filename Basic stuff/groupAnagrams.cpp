#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    map<string, vector<string>> mpcount;
    int n = strs.size(), j = 0;

    for(int i = 0; i < n; i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        mpcount[s].push_back(strs[i]);
    }

    //can be replace with 
    //[ map<string, vector<string>>::iterator it = mpcount.begin(); it != mpcount.end(); it++ ]
    for(auto it:mpcount) {
        res.push_back(it.second);
    }

    return res;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> res = groupAnagrams(strs);
    cout << "[";
    for(int i = 0; i < res.size(); i++) {
        cout << "[";
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]";

    return 0;
}