#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s) {
    stack<char> par;
    for(string::iterator it = s.begin(); it!=s.end(); ++it) {
        if(*it == '(' || *it == '[' || *it == '{') {
            par.push(*it);
        } else {
            if(par.empty()) {
                return false;
            }
            char s_top = par.top();
            par.pop();
            if((*it == ')' && s_top == '(') || (*it == ']' && s_top == '[') || (*it == '}' && s_top == '{')) {
                continue;
            } else {
                return false;
            }
        }
    }
    return par.empty();
}
int main() {
    cout << isValid("([)]");
}