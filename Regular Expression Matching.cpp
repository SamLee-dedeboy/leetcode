#include <iostream>
using namespace std;


bool isMatch3(string s, string p) {
    if(p == ".*") {
        return true;
    }

    string::iterator si = s.begin();
    string::iterator pi = p.begin();
    if(s.empty() && p.empty()) {
        return true;
    } else if(p.empty() && !s.empty()) {
        return false;
    } else if(s.empty() && !p.empty()) {
        if(pi == p.end() - 1) {
            return false;
        }
        pi += 1;
        while(pi!=p.end()) {
           if(*pi != '*') {
               return false;
           }
           ++pi;
           if(pi == p.end()) {
               return true;
           } else if(pi == p.end() - 1) {
               return false;
           } else {
               ++pi;
           }
        }
        return true;
    }
    
    if(*si == *pi || *pi == '.') {
        if(*(pi+1) == '*') {
            return isMatch(s,p.substr(2)) || isMatch(s.substr(1),p);
        } else {
            return isMatch(s.substr(1), p.substr(1));
        }
    } else {
        if(*(pi+1) == '*') {
            return isMatch(s,p.substr(2));
        } else {
            return false;
        }
    } 
}
bool isMatch2(string s, string p) {
    if(p == ".*") {
        return true;
    }
    
    string::reverse_iterator rsi = s.rbegin();
    string::reverse_iterator rpi = p.rbegin();
    if(s.empty()) {
        while(rpi != p.rend()) {
            if(*rpi == '*') {
                rpi += 2;
            } else {
                return false;
            }
        }
        return true;
    }
    while(true) {
        cout << *rsi << " " << *rpi << endl;
        if(*rsi == *rpi) {
            ++rsi;
            ++rpi;
            if(rsi == s.rend() && rpi == p.rend()) {
                return true;
            } else if(rsi != s.rend() && rpi != p.rend()){
                continue;
            } else if(rpi == p.rend()){
                return false;
            } else {
                if(*rpi == '*') {
                    if(*(rpi+1) == '.') {
                        return true;
                    }
                    while(rpi != p.rend()) {
                        if(*rpi == '*') {
                            rpi += 2;
                        } else {
                            return false;
                        }
                    }
                    return true;
                } else {
                    return false;
                }
            }
        } else if(*rpi == '.') {
            ++rsi;
            ++rpi;
            if(rsi == s.rend() && rpi == p.rend()) {
                return true;
            } else if(rsi != s.rend() && rpi != p.rend()){
                continue;
            } else if(rpi == p.rend()){
                return false;
            } else {
                if(*rpi == '*') {
                    if(*(rpi+1) == '.') {
                        return true;
                    }
                    while(rpi != p.rend()) {
                        if(*rpi == '*') {
                            rpi += 2;
                        } else {
                            return false;
                        }
                    }
                    return true;
                } else {
                    return false;
                }
            }
        } else if(*rpi == '*') {
            if(*(rpi+1) == '.') {
                return true;
            }
            if(*rsi == *(rpi+1)) {
                ++rsi;
                if(rsi == s.rend()) {
                    while(rpi != p.rend()) {
                        if(*rpi == '*') {
                            rpi += 2;
                        } else if(rpi == p.rend()-1 && *rpi == *(rsi-1)){
                            return true;
                        } else {
                            return false;
                        }
                    }
                    return true;
                }
                continue;
            } else {
                rpi += 2;
                if(rpi == p.rend()) {
                    return false;
                }
                continue;
            }
        } else if(rpi != p.rend()-1 && *(rpi+1) == '*') {
            rpi += 2;
            continue;
        } else {
            return false;
        }
    }
    return true;
}        

int main() {
    cout << isMatch("aasdfasdfasdfasdfas","aasdf.*asdf.*asdf.*asdf.*s");
}