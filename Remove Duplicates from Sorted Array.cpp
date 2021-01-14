#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2) {
        return nums.size();
    }
    int index = 0;
    for(int i = 1; i < nums.length(); ++i) {
        if(nums[i] != nums[index]) {
            ++index;
            nums[index] = nums[i];
        }
    }
    return index+1;
}
int main() {
    vector<int> inp {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(inp);
}