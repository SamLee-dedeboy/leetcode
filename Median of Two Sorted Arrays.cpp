#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    if(size1 == 0) {
        if(size2 %2 == 1) {
            return nums2[size2/2];
        } else {
            return (double)(nums2[size2/2 - 1] + nums2[size2/2])/2;
        }
    }

    if(size2 == 0) {
        if(size1 %2 == 1) {
            return nums1[size1/2];
        } else {
            return (double)(nums1[size1/2 - 1] + nums1[size1/2])/2;
        }
    }

    int total_size = nums1.size() + nums2.size();
    //cout << total_size << endl;
    size_t i = 0, j = 0;
    int steps = 0;
    while(steps<(total_size-1)/2) {
        //cout << steps << ": " << nums1[i] << ", " << nums2[j] << " --> ";

        if(nums1[i] < nums2[j]) {
            i++;
        } else if(nums1[i] > nums2[j]){
            j++;
        } else {
            if(i+1<nums1.size()&&j+1<nums2.size()) {
                if(nums1[i+1] <= nums2[j+1]) {
                    i++;
                } else {
                    j++;
                }
            } else {
                if(i+1 >= nums2.size()) {
                    i++;
                } else { 
                    j++;
                }
            }
        }
        steps++;

       // cout << nums1[i] << ", " << nums2[j] << endl;
        if(i == nums1.size() || j == nums2.size())
            break;

    }
    cout << i << ", " << j << endl;
    if(i < nums1.size() && j < nums2.size()) {
        if(steps == (total_size-1)/2) {
            if(total_size % 2 == 1) {
                return nums1[i]<nums2[j]?nums1[i]:nums2[j];
            }
            else {
                int mid2;
                if(nums1[i] < nums2[j]) {
                    if(i+1 < nums1.size())
                        mid2 = nums1[i+1] < nums2[j]? nums1[i+1]:nums2[j];
                    else 
                        mid2 = nums2[j];
                    return (double)(nums1[i] + mid2)/2;
                } else {
                    if(j+1 < nums2.size())
                        mid2 = nums1[i] < nums2[j+1]? nums1[i]:nums2[j+1];
                    else 
                        mid2 = nums1[i];
                    
                    return (double)(nums2[j] + mid2)/2;
                }
            }
        }
    }
    if(i < nums1.size()) {
        i+=(total_size-1)/2-steps;
        if(total_size % 2 == 1) 
                return nums1[i];
            else 
                return (double)(nums1[i] + nums1[i+1])/2;
    } else {
        j+=(total_size-1)/2-steps;
        if(total_size % 2 == 1) 
                return nums2[j];
            else 
                return (double)(nums2[j] + nums2[j+1])/2;
    }
}
int main() {
    vector<int> nums1 {4};
    vector<int> nums2 {1,2,3};
    cout << findMedianSortedArrays(nums1, nums2);
}