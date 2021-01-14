#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int len = words[0].length(); 
    for(int start = 0; start <= s.length() - words.size()*len; ++start) {
        unordered_multiset<string> words_set(words.begin(), words.end());
        int pos = start;
        while(pos <= s.length() - len) {
            string str = s.substr(pos,len);
            cout << str << " ";
            unordered_multiset<string>::iterator it;
            it = words_set.find(str);
            if(it != words_set.end()) {
                words_set.erase(it);

                if(words_set.empty()) {
                    res.push_back(start);
                    break;
                }
            } else {
                break;
            }
            pos += len;
        }
        cout << endl;
    }
    return res;
}

int main() {
    vector<string> words {"foo","bar"};
    vector<int> res = findSubstring("barfoothefoobarman", words);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}