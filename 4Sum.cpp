#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int qua_target) {
    vector<vector<int>> res;
    if(nums.size() < 4) {
        return res;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-3; ++i) {
        if(i!=0 && nums[i] == nums[i-1]) {
            continue;
        }
        for(int j = i+1; j < nums.size()-2; ++j) {
            if(j!=i+1 && nums[j] == nums[j-1]) {
                continue;
            }
            int target = qua_target-(nums[i]+nums[j]);

            //reduce to 2 sum
            int left = j+1, right = nums.size() - 1;
            while(left<right) {
                if(nums[left] + nums[right] == target) {
                    vector<int> quadruple {nums[i],nums[j],nums[left],nums[right]};
                    printf("%d %d %d %d -> %d\n", nums[i], nums[j],nums[left], nums[right],target);
                    res.push_back(quadruple);
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
    } 
    return res;
}
int main() {
    vector<int> inp {-2,-1,-1,1,1,2,2};
    fourSum(inp,0);
}
