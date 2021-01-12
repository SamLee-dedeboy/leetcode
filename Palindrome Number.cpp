#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }
    int tmp = x;
    long long base = 1;
    while(tmp>=10) {
        tmp /= 10;
        base *= 10;
    }
    //cout << base << endl;
    while(base >= 10) {
        if(x / base == 0) {
            return false;
        }
        if(x < 10) { 
            break;
        }
        long long tail = x%10;
        long long head = (x/base)%10;
        //cout << head << ", " << tail << endl;
       
        x /= 10;
        base /= 100;
       // cout << x << " " << base << endl;
        if(tail == head) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}
int main() {
    cout << isPalindrome(121);
}