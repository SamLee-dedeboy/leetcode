#include <iostream>
using namespace std;
int strStr(string haystack, string needle) {
    if(needle.empty()) {
        return 0;
    }
    int pos = 0;
    for(string::iterator it = haystack.begin(); it!=haystack.end(); ++it) {
        int distance = 0;
        for(string::iterator target = needle.begin(); target!=needle.end(); ++target) {
            if(*(it+distance) != *target) {
                break;
            }
            ++distance;
            if(distance ==  needle.size()) {
                //cout << distance;
                return pos;
            }
        }
        ++pos;
    }       
    return -1;
}
int main() {
    cout << strStr("aaaaa", "bba");
}