#include <iostream>
using namespace std;
int strStr(string haystack, string needle) {
    if(needle.empty()) {
        return 0;
    }
    int pos = 0;
    int n = haystack.length() - needle.length() + 1;
    for(int i = 0; i < n; ++i) {
        int distance = 0, k = i;
        while(distance < needle.length() && haystack[k] == needle[distance]) {
            ++k;
            ++distance;
        }
        if(distance ==  needle.length()) {
            //cout << distance;
            return i;
        }
    }       
    return -1;
}
int main() {
    cout << strStr("aaaaa", "bba");
}