#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> spar;
    int max_length = 0;
    spar.push(-1);
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '(') {
            spar.push(i);
        } else if(s[i] == ')') {
            spar.pop();
            if(spar.empty()) {
                spar.push(i);
            } else {
                max_length = max_length > i - spar.top() ? max_length:i-spar.top();
            }
        }
    }

    return max_length;
}
int main() {
    cout << longestValidParentheses("(()(((()");
}