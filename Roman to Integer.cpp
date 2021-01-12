#include <iostream>
using namespace std;

int romanToInt(string s) {
    int res = 0;
    for(string::iterator si = s.begin(); si!=s.end(); ++si) {
        if(*si == 'I') {
            if(si != s.end()-1) {
                if(*(si+1) == 'V') {
                    ++si;
                    res += 4;
                    continue;
                } else if(*(si+1) == 'X') {
                    ++si;
                    res += 9;
                    continue;
                } 
            } 
            res += 1;
            continue;
        } else if(*si == 'V') {
            res += 5;
            continue;
        } else if(*si == 'X') {
           if(si != s.end()-1) {
                if(*(si+1) == 'L') {
                    res += 40;
                    ++si;
                    continue;
                } else if(*(si+1) == 'C') {
                    res += 90;
                     ++si;
                    continue;
                } 
            } 
            res += 10;
            continue;     
        } else if(*si == 'L') {
            res += 50;
            continue;
        } else if(*si == 'C') {
            if(si != s.end()-1) {
                if(*(si+1) == 'D') {
                    res += 400;
                    ++si;
                    continue;
                } else if(*(si+1) == 'M') {
                    res += 900;
                     ++si;
                    continue;
                } 
            } 
            res += 100;
            continue;  
        } else if(*si == 'D') {
            res += 500;
            continue;
        } else if(*si == 'M') {
            res += 1000;
            continue;
        }
    }
    return res;
}
int main() {
    cout << romanToInt("MCMXCIV");
}