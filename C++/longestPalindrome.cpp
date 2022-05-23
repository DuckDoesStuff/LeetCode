#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(string s) {
    int n = s.length();

    for(int i = 0; i <= n/2; i++) {
        if(toupper(s[i]) != toupper(s[n - i - 1])) return false;
    }
    return true;
}

//brute-force with sliding window
//not a very optimized solution for long string
string longestPalindrome(string s) {
    int n = s.length();
    if(n == 1) return s;
    string result = "";

    for(int i = 0; i < n - 1; i++) {
        int left = i, right = i;
        string temp;
        while(left >= 0 && right < n && s[left] == s[right]) {
            if(right - left + 1 > result.length())
                result = s.substr(left, right - left + 1);
            left--;
            right++;
        }

        left = i, right = i + 1;
        while(left >= 0 && right < n && s[left] == s[right]) {
            if(right - left + 1 > result.length())
                result = s.substr(left, right - left + 1);
            left--;
            right++;
        }
    }
    return result;
}

int main() {
    string s = "twbiqwtafgjbtolwprpdnymaatlbuacrmzzwhkpvuwdtyfjsbsqxrlxxtqkjlpkvpxmlajdmnyepsmczmmfdtjfbyybotpoebilayqzvqztqgddpcgpelwmriwmoeeilpetbxoyktizwcqeeivzgxacuotnlzutdowiudwuqnghjgoeyojikjhlmcsrctvnahnoapmkcrqmwixpbtirkasbyajenknuccojooxfwdeflmxoueasvuovcayisflogtpxtbvcxfmydjupwihnxlpuxxcclbhvutvvshcaikuedhyuksbwwjsnssizoedjkbybwndxpkwcdxaexagazztuiuxphxcedqstahmevkwlayktrubjypzpaiwexkwbxcrqhkpqevhxbyipkmlqmmmogrnexsztsbkvebjgybrolttvnidnntpgvsawgaobycfaaviljsvyuaanguhohsepbthgjyqkicyaxkytshqmtxhilcjxdpcbmvnpippdrpggyohwyswuydyrhczlxyyzregpvxyfwpzvmjuukswcgpenygmnfwdlryobeginxwqjhxtmbpnccwdaylhvtkgjpeyydkxcqarkwvrmwbxeetmhyoudfuuwxcviabkqyhrvxbjmqcqgjjepmalyppymatylhdrazxytixtwwqqqlrcusxyxzymrnryyernrxbgrphsioxrxhmxwzsytmhnosnrpwtphaunprdtbpwapgjjqcnykgspjsxslxztfsuflijbeebwyyowjzpsbjcdabxmxhtweppffglvhfloprfavduzbgkw";
    cout << longestPalindrome(s);

    return 0;
}