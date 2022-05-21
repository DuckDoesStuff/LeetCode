#include <iostream>
#include <stack>

using namespace std;

char check(char c) {
    if(c == '}') return '{';
    if(c == ']') return '[';
    if(c == ')') return '(';
    return 'e';
}

bool isValid(string s) {
    stack<char> stk;
    stk.push('a');//random init chars :v

    for(int i = 0; i < s.length(); i++) {
        if(check(s[i]) == stk.top()) stk.pop();
        else stk.push(s[i]);
    }

    return stk.size() == 1 ? true : false;
}

int main() {
    string s = {"(]"};
    cout << isValid(s);
    return 0;
}