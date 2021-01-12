#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() < 3) {
        return res;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; ++i) {
        if(i!=0 && nums[i] == nums[i-1]) {
            continue;
        }
        int target = -nums[i];
        //reduce to 2 sum
        int left = i+1, right = nums.size() - 1;
        while(left<right) {
            if(nums[left] + nums[right] == target) {
                vector<int> tripple {nums[i],nums[left],nums[right]};
                printf("%d %d %d\n", nums[i], nums[left], nums[right]);
                res.push_back(tripple);
                ++left;
                while(left < right && nums[left] == nums[left-1]) {
                    ++left;
                }
                --right;
                while(right > left && nums[right] == nums[right+1]) {
                    --right;
                }
            } else if(nums[left] + nums[right] > target) {
                --right;
                while(right > left && nums[right] == nums[right+1]) {
                    --right;
                }
            } else if(nums[left] + nums[right] < target) {
                ++left;
                while(left < right && nums[left] == nums[left-1]) {
                    ++left;
                }
            }
        }
    }        
    return res;
}
int main() {
    vector<int> inp {0,0,0};
    threeSum(inp);
}
