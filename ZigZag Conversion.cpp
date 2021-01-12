#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) {
        return s;
    }
    string res;
    int len = s.length();
    //cout << len << endl;
    int cycleLen = 2*numRows - 2;
    int numCycles = len / cycleLen;
    int lastCycle = len % cycleLen == 0 ? 0:1;
    int lastCol = lastCycle / numRows;
    int lastZig = lastCycle % numRows;
    //cout << lastCycle << endl;
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numCycles + lastCycle; ++j) {
            int index = cycleLen*j+i;
            if(index < len) {
                res += s[cycleLen*j+i];
            }
            
            //cout << s[cycleLen*j+i] << " ";
            if(i!=0 && i!=numRows - 1) {
                int singular_index = cycleLen*(j+1)-i;
                //cout << "sin: " << singular_index << endl;
                if(singular_index < len) {
                    res += s[singular_index];
                    //cout << s[singular_index] << " ";

                }
            }
        }
        //cout<<endl;
    }
    //cout << res << endl;
    return res;
}
int main () {
    cout << convert("A",1);
}