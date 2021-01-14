#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int min = nums.back();
    int min_index = nums.size()-1;
    int min_gap = 2147483647;
    int next_index = -1;
    for(int i = nums.size()-1; i > 0; --i) {
        if(nums[i-1] < nums[i]) {
            int min_gap = 2147483647;
            int next_index = i;
            int anchor = i-1;
            for(int j = i; j < nums.size(); ++j) {
                int gap = nums[j] - nums[anchor];
                if(gap <= 0) {
                    break;
                } else if(gap < min_gap) {
                    min_gap = gap;
                    next_index = j;
                }
            }
            int tmp = nums[anchor];
            nums[anchor] = nums[next_index];
            nums[next_index] = tmp;
            sort(nums.begin()+anchor+1, nums.end());
            return;
        } 
    }
    reverse(nums.begin(), nums.end());
    
    return;
}
int main() {
    vector<int> inp {1,5,1};
    nextPermutation(inp);
    for(int i = 0; i < inp.size(); ++i) {
        cout << inp[i] << " ";
    }
}