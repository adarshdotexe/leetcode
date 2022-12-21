#include <iostream>
#include <vector>

using namespace std;

/*
    * 287. Find the Duplicate Number
    * https://leetcode.com/problems/find-the-duplicate-number/
    *
    * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
    * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
    * find the duplicate one.
    *
    * Example 1:
    * Input: [1,3,4,2,2]
    * Output: 2
    *
    * Example 2:
    * Input: [3,1,3,4,2]
    * Output: 3
    *
    * Note:
    * You must not modify the array (assume the array is read only).
    * You must use only constant, O(1) extra space.
    * Your runtime complexity should be less than O(n2).
    * There is only one duplicate number in the array, but it could be repeated more than once.
    *
    * Solution:
    * 1. Sort the array and find the duplicate number.
    * 2. Use a hash table to find the duplicate number.
    * 3. Use a set to find the duplicate number.
    * 4. Use binary search to find the duplicate number.
    * 5. Use Floyd's Tortoise and Hare (Cycle Detection) to find the duplicate number.
*/

// 5. Use Floyd's Tortoise and Hare (Cycle Detection) to find the duplicate number.
// Mathematically, the duplicate number is the entry point of the cycle.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0; 
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);
        fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while(slow!=fast);
        return slow;
    }

    int main() {
        vector<int> nums = {1,3,4,2,2};
        cout << findDuplicate(nums) << endl;
        return 0;
    }
};