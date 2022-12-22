#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    * 15. 3Sum
    * https://leetcode.com/problems/3sum/
    *
    * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
    * Find all unique triplets in the array which gives the sum of zero.
    *
    * Note:
    * The solution set must not contain duplicate triplets.
    *
    * Example:
    * Given array nums = [-1, 0, 1, 2, -1, -4],
    * A solution set is:
    * [
    *   [-1, 0, 1],
    *   [-1, -1, 2]
    * ]
    *
    * Solution:
    * 1. Sort the array and use two pointers to find the triplets.
    * 2. Use a hash table to find the triplets.
*/


// 1. Sort the array and use two pointers to find the triplets.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); i++) {
            // Skip the element if it is the same as the previous element
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1;
            int right = nums.size() - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    // Skip the duplicate elements
                    while (left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (total < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return triplets;
    }

    void printVector(vector<vector<int>> triplets) {
        for (int i = 0; i < triplets.size(); i++) {
            for (int j = 0; j < triplets[i].size(); j++) {
                cout << triplets[i][j] << " ";
            }
            cout << endl;
        }
    }

    int main() {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> triplets = threeSum(nums);
        printVector(triplets);
        return 0;
    }
};