#include <iostream>
using namespace std;

int reverse(int x) {
    if(x == -2147483648) {
        return 0;
    }
    cout << x << endl;
    long long res = 0;
    long long base = 1;
    bool negative = false;
    if(x < 0) {
        x *= -1;
        negative = true;
    }
    int tmp = x;
    while(tmp>=10) {
        tmp /= 10;
        base *= 10;
    }
    cout << base << endl;
    cout << res << endl;
    while(x!=0) {
        long long digit = x%10;
        cout << digit << ", " << base << endl;
        res += digit*base;
        x /= 10;
        base /= 10;
        cout << res << endl;
    }
    if(res >= 2147483647)
        return 0;
    if(negative) 
        return -res;
    else 
        return res;

}
int main() {
    cout << reverse(-2147483648);
}