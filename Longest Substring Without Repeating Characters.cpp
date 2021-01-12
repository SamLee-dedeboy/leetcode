#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.empty())
        return 0;
    string res = "";
    int startpos = 0;
    size_t maxLength = 0;
    int head = 0;
    while(startpos < s.size()) {
        //cout<< head << ", " << startpos << endl;
        string sub = s.substr(head,startpos-head+1);
        size_t length = 0;
        int new_head = 0;
        for(string::iterator it = s.begin()+startpos+1; it!=s.end(); ++it) {
            size_t found = sub.find(*it);
            if(found == string::npos) {
                sub+=*it;
            } else {
                new_head = found+head+1;
                //cout << sub << endl;
                break;
            }
        }
        length = sub.size();

        if(length>maxLength)
            maxLength = length;
        startpos = head + length;
        head = new_head;
    }
    return maxLength;
}

int main() {
    string s = "";
    cout << lengthOfLongestSubstring(s);
}