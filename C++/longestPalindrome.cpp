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
        int j = i + 1;
        while(j <= n) {
            string temp = s.substr(i, j - i);
            if(checkPalindrome(temp) && temp.length() > result.length()) result = temp;
            j++;
        }
    }
    return result;
}

int main() {
    string s = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";
    cout << longestPalindrome(s);

    return 0;
}