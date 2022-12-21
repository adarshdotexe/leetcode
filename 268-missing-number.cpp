#include <iostream>
#include <vector>

using namespace std;

/*
    * 268. Missing Number
    * https://leetcode.com/problems/missing-number/
    *
    * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
    *
    * Example 1:
    * Input: [3,0,1]
    * Output: 2
    *
    * Example 2:
    * Input: [9,6,4,2,3,5,7,0,1]
    * Output: 8
    *
    * Note:
    * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
    *
    * Solution:
    * 1. Sort the array and find the missing number.
    * 2. Use sum to find the missing number.
    * 3. Use XOR to find the missing number.
*/

// 3. Use XOR to find the missing number.
// Proof:
// 1. XOR is commutative: a ^ b = b ^ a
// 2. XOR is associative: a ^ (b ^ c) = (a ^ b) ^ c
// 3. XOR with zero: a ^ 0 = a
// 4. XOR with itself: a ^ a = 0

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();                // n = 3
        int x = 0;                          // x = 0
        for (int i = 0; i < n; i++) {       // i = 0, 1, 2
            x ^= nums[i];                   // x = 0 ^ 3 ^ 0 ^ 1 = 2
            x ^= i;                         // x = 2 ^ 0 ^ 1 ^ 2 = 1
        }
        return x ^ n;                       // x = 1 ^ 3 = 2
    }

    int main() {
        vector<int> nums = {3,0,1};
        cout << missingNumber(nums) << endl;
        return 0;
    }
};