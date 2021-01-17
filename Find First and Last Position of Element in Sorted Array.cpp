#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == target) {
            res.push_back(i);
            for(int j = i; j < nums.size(); ++j) {
                if(nums[j] == target) {
                    continue;
                } else {
                    res.push_back(j-1);
                    return res;
                }
            }
            res.push_back(nums.size()-1);
            return res;
        }
    }
    res.push_back(-1);
    res.push_back(-1);
    return res;
}
int main() {
         
}