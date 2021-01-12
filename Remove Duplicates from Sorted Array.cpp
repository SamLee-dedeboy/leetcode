#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2) {
        return nums.size();
    }
    int index = 1;
    while(index < nums.size()) {
        if(nums[index] == nums[index-1]) {
            nums.erase(nums.begin() + index);
        } else {
            ++index;
        }
    }
    return nums.size();
}
int main() {
    vector<int> inp {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(inp);
}