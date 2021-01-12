#include <iostream>
using namespace std;

int myAtoi(string s) {
    bool negative_flag = false;
    long long res = 0;
    bool find_digit = false;
    for(string::iterator it = s.begin(); it != s.end(); ++it) {
        if(find_digit) {
            if(isdigit(*it)) {
                res = res*10+(*it - 48);
                if(negative_flag && res >= 2147483648) {
                    return -2147483648;
                } else if(res > 2147483647) {
                    return 2147483647;
                }
            } else {
                break;
            }
        } else if(*it == ' ') {
            continue;
        } else if(*it == '+' && it!=s.end()-1 && isdigit(*(it+1))) {
            continue;
        } else if(isdigit(*it)) {
            find_digit = true;
            res = *it-48;
        } else if(*it == '-' && it!=s.end()-1 && isdigit(*(it+1))) {
            negative_flag = true;
        } else {
            return 0;
        }
    }
    if(negative_flag) {
        return -res;
    } else {
        return res;
    }
}

int main() {
    cout << myAtoi("-2147483648");
}