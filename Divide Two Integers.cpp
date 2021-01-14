#include <iostream>
using namespace std;
int divide(int dividend, int divisor) {
    if(dividend == -2147483648 && divisor == -1) {
        return 2147483647;
    }
    if(dividend == 0) {
        return 0;
    }
    int flag = 1;
    if(dividend < 0) {
        flag *= -1;
        dividend *= -1;
    }
    if(divisor < 0) {
        flag *= -1;
        divisor *= -1;
    }
    int res = 0;
    while(dividend >= divisor) {
        dividend -= divisor;
        ++res;
    }
    return res*flag;
}
int main() {
    cout << divide(1,1);
}