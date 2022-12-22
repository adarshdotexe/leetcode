#include <iostream>
#include <vector>

using namespace std;

/*
    * 11. Container With Most Water
    * https://leetcode.com/problems/container-with-most-water/
    *
    * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
    * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
    * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
    *
    * Note: You may not slant the container and n is at least 2.
    *
    * Example:
    * Input: [1,8,6,2,5,4,8,3,7]
    * Output: 49
    *
    * Solution:
    * 1. Brute force: O(n^2)
    * 2. Two pointers: O(n)
*/

// 2. Two pointers: O(n)
// Proof:
// 1. Assume the max area is between the left and right pointers.
// 2. If the left pointer is shorter than the right pointer, then the max area is limited by the left pointer.
// 3. If the left pointer is longer than the right pointer, then the max area is limited by the right pointer.
// 4. If we move to a shorter pointer then the max area will decrease.


class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                int left_height = height[left];
                while (left < right && height[left] <= left_height) {
                    left++;
                }
            } else {
                int right_height = height[right];
                while (left < right && height[right] <= right_height) {
                    right--;
                }
            }
        }
        return max_area;
    }
    
    int main() {
        vector<int> height = {1,8,6,2,5,4,8,3,7};
        cout << maxArea(height) << endl;
        return 0;
    }

};
