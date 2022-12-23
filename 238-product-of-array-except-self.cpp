#include <iostream>
#include <vector>

using namespace std;

/*
    * 238. Product of Array Except Self
    * https://leetcode.com/problems/product-of-array-except-self/
    *
    * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
    * Example:
    * Input:  [1,2,3,4]
    * Output: [24,12,8,6]
    * Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
    * Note: Please solve it without division and in O(n).
    * Follow up:
    * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
    *
    * Solution:
    * 1. Use two arrays to store the left and right products.
    * 2. Use ans array to store the left products and update the ans array to store the final answer.
*/

// 2. Use ans array to store the left products and update the ans array to store the final answer.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Calculate left products
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // Calculate right products
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }

        return answer;
    }

    void printVector(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    int main() {
        vector<int> nums = {1,2,3,4};
        vector<int> answer = productExceptSelf(nums);
        printVector(answer);
        return 0;
    }
};