#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    
    int min_gap = 2147483647;
    int min_sum;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; ++i) {
        if(i!=0 && nums[i] == nums[i-1]) {
            continue;
        }
        //reduce to 2 sum
        int left = i+1, right = nums.size() - 1;
        while(left<right) {
            int cur_sum = nums[left] + nums[right] + nums[i];
            //printf("%d %d %d %d\n", nums[left], nums[right], nums[i], cur_sum);

            if(cur_sum == target) {
                return target;
            } else if(cur_sum > target) {
                --right;
            } else if(cur_sum < target) {
                ++left;
                
            }
            if(abs(cur_sum - target) < min_gap) {
                min_gap = abs(cur_sum - target);
                min_sum = cur_sum;
            }
        }
    }        
    return min_sum;
}
int main() {
    vector<int> inp {1,2,5,10,11};
    cout << threeSumClosest(inp,12);
}