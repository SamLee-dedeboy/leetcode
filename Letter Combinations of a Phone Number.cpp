#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> dicar(vector<string> a, vector<string> last) {
    vector<string> res;
    if(last.empty()) {
        return a;
    } else {
        for(int i = 0; i < last.size(); ++i) {
            for(int j = 0; j < a.size(); ++j) {
                res.push_back(last[i]+a[j]);
            }
        }
    }
    return res;
}
vector<string> letterCombinations(string digits) {
    vector<string> res;
    
    vector<vector<string>> map
     {{"a","b","c"},
    {"d","e","f"},
    {"g","h","i"},
    {"j","k","l"},
    {"m","n","o"},
    {"p","q","r","s"},
    {"t","u","v"},
    {"w","x","y","z"}};
    
    for(string::iterator it = digits.begin(); it!=digits.end(); ++it) {
        vector<string> alphabet = map[*it-48-2];
        res = dicar(alphabet,res);
    }
    return res;
}



int main() {
  
    vector<string> res = letterCombinations("234");
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}