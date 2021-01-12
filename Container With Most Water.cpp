#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int max = 0;
    int max_height_left = 0;
    int max_height_right = 0;
    for(int i = 0, j = height.size()-1; i != j;) {
        int area = 0;
        if(height[i] < max_height_left) {
            ++i;
            continue;
        } else {
            max_height_left = height[i];
        }
        if(height[j] < max_height_right) {
            --j;
            continue;
        } else {
            max_height_right = height[j];
        }
        if(height[i] < height[j]) {
            area = height[i]*(j-i);
            ++i;
        } else {
            area = height[j]*(j-i);
            --j;
        }
        if(area > max) {
            max = area;
        }
    }
    return max;
}
int main() {
    vector<int> height {1,1};
    cout << maxArea(height);
}