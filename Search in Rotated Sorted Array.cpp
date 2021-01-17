#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size() == 1) {
        return (nums[0]==target) - 1;
    }
    bool flag = target <= nums.back(); // true - target in right; false - target in left
    int left = 0, right = nums.size()-1;
    int pivot = (left+right)/2;
    while(nums[pivot]<nums[pivot+1]) {
        if(nums[pivot] > nums[left]) {
            left = pivot;
        } else {
            right = pivot;
        }
        int former_pivot = pivot;
        pivot = (left+right)/2;
        if(former_pivot == pivot) {
            //no pivot
            if(target < nums[0] || target > nums.back()) {
                return -1;
            } else {
                pivot = -1;
                break;
            }
        }
    }
    if(flag) {
        //binary search in right group
        left = pivot+1;
        right = nums.size()-1;
    } else {
        //binary search in left group
        left = 0;
        right = pivot;
    }
    cout << left << " " << right << endl;
    if(left == right) {
        if(nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }
    while(left < right) {
        int mid = (left+right)/2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            if(left == mid) {
                if(nums[right] == target) {
                    return right;
                } else {
                    return -1;
                }
            }
            left = mid;
        } else {
            if(right == mid) {
                return -1;
            }
            right = mid;
        }
    }
    return -1;
}
int main() {
    vector<int> nums {3,1};
    cout << search(nums,1);
}