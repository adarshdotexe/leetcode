#include <iostream>
#include <vector>

using namespace std;

/*
 * 4. Median of Two Sorted Arrays
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 *
 * Solution:
 * 1. Merge two sorted arrays and find the median.
 * 2. Use binary search to find the median.
 */

// 2. Use binary search to find the median.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // Ensure that nums1 is the shorter array
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int i, j, min_i = 0, max_i = m, half = (m + n + 1) / 2;
        while (min_i <= max_i) {
            i = (min_i + max_i) / 2;
            j = half - i;
            if (i < m && nums2[j - 1] > nums1[i]) {
                min_i = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                max_i = i - 1;
            } else {
                int max_left;
                if (i == 0) {
                    max_left = nums2[j - 1];
                } else if (j == 0) {
                    max_left = nums1[i - 1];
                } else {
                    max_left = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return max_left;
                }
                int min_right;
                if (i == m) {
                    min_right = nums2[j];
                } else if (j == n) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums1[i], nums2[j]);
                }
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }

    int main() {
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {3, 4};
        cout << findMedianSortedArrays(nums1, nums2) << endl;
    }
};

// The binary search approach for finding the median of two sorted arrays works
// by dividing the arrays into two parts at each step of the search, such that 
// the combined length of the left parts is equal to the combined length of the
// right parts. This ensures that the median, if it exists, must be one of the 
// elements in the left or right parts.

// To implement this, we use two variables, i and j, to represent the sizes of 
// the left parts of nums1 and nums2, respectively. We perform a binary search 
// over i, and for each value of i we set j = (m + n + 1) / 2 - i, where m and
// n are the lengths of nums1 and nums2, respectively. This ensures that the
// combined length of the left parts is equal to the combined length of the right parts.

// Then, we compare the last element of the left part of nums1 (nums1[i - 1])
// with the first element of the right part of nums2 (nums2[j]), and the last
// element of the left part of nums2 (nums2[j - 1]) with the first element of
// the right part of nums1 (nums1[i]). Based on these comparisons,
// we can determine whether the median is in the left or right parts, or
// whether we have found the median.

// If nums1[i - 1] > nums2[j], it means that the median must be in the left part of nums1 or the right part of nums2, so we update the search range to [min_i, i - 1].

// If nums2[j - 1] > nums1[i], it means that the median must be in the left part of nums2 or the right part of nums1, so we update the search range to [i + 1, max_i].

// If neither of these conditions is true, it means that we have found the median.
// If the combined length of the two arrays is odd, the median is the maximum of the last element of the left part of nums1 and the last element of the left part of nums2.
// If the combined length of the two arrays is even, the median is the average of the maximum of the last element of the left part of nums1 and the last element of the left part of nums2, and the minimum of the first element of the right part of nums1 and the first element of the right part of nums2.

// We repeat this process until we have found the median or the search range becomes empty.

// Time complexity: O(log(min(m, n)))