#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
     if(strs.size() == 0) {
        return "";
    } else if(strs.size() == 1) {
        return strs[0];
    }
    string str1 = strs[0];
    string str2 = strs[1];
    string common_prefix;
    for(string::iterator s1 = str1.begin(), s2 = str2.begin(); s1 != str1.end() && s2 != str2.end(); ++s1,++s2) {
        if(*s1 == *s2) {
            common_prefix += *s1;
        } else {
            break;
        }
    }
    for(int i = 2; i < strs.size(); ++i) {
        if(strs[i].empty()) {
            return "";
        }
        if(common_prefix.empty()) {
            return "";
        }
        string common_prefix_tmp;

        for(string::iterator it = strs[i].begin(), ic = common_prefix.begin(); it!=strs[i].end() && ic!=common_prefix.end(); ++it, ++ic) {
            if(*it == *ic) {
                common_prefix_tmp += *it;
                continue;
            } else {
                break;
            }
        }
        common_prefix = common_prefix_tmp;

    }
    return common_prefix;
}   
int main() {
    vector<string> strs {"ac","ac","a","a"};
    cout << longestCommonPrefix(strs) << endl;
}