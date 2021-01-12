#include <iostream>
#include <vector>
using namespace std;
void dfs(int open, int close, string tmp, vector<string>& res) {
    if(open == 0 && close == 0) {
        res.push_back(tmp);
        return;
    }
    if(open > 0) {
        dfs(open-1, close+1, tmp+"(", res);
    }
    if(close > 0) {
        dfs(open, close-1, tmp+")", res);
    }
    return;
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(n,0,"",res);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return res;
}

int main() {
    generateParenthesis(3);
}