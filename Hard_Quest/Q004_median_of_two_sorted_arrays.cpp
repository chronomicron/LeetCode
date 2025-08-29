// LeetCode Problem 4: Median of Two Sorted Arrays
// Difficulty: Hard
// Description: Given two sorted arrays nums1 (size m) and nums2 (size n), find the
//              median of the merged sorted array. The median is the middle element
//              (if m+n is odd) or the average of the two middle elements (if m+n is even).
//              The solution must run in O(log(min(m,n))) time.
// Constraints:
//   - nums1.length == m
//   - nums2.length == n
//   - 0 <= m, n <= 1000
//   - 1 <= m + n <= 2000
//   - -10^6 <= nums1[i], nums2[i] <= 10^6
// Algorithmic Pattern: Modified Binary Search
//   - Perform binary search on the smaller array to find a partition point that splits
//     the merged array into two equal halves (or nearly equal for odd length). Check
//     if the partition satisfies the median condition. Use O(log(min(m,n))) time and O(1) space.

#include <vector>
#include <iostream>
#include <climits> // For INT_MIN, INT_MAX
#include <algorithm> // For max, min

using namespace std;

// Helper function to print vector contents in [a, b, c] format
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Get the sizes of both input arrays
        int size_nums1 = nums1.size();
        int size_nums2 = nums2.size();

        // Step 2: Ensure nums1 is the smaller array to minimize binary search range
        //         If nums1 is larger, swap the arrays by calling the function recursively
        if (size_nums1 > size_nums2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Step 3: Calculate the total length of the merged array
        int total_length = size_nums1 + size_nums2;

        // Step 4: Calculate the size of the left half of the merged array
        //         For odd total length (e.g., 5), left half has (5+1)/2 = 3 elements
        //         For even total length (e.g., 4), left half has (4+1)/2 = 2.5 = 2 elements
        int half_length = (total_length + 1) / 2;

        // Step 5: Initialize binary search boundaries for partitioning nums1
        //         Start with the full range of nums1: [0, size_nums1]
        int low_partition_x = 0;
        int high_partition_x = size_nums1;

        // Step 6: Perform binary search to find the correct partition point
        //         Use while(true) loop with explicit breaks, as requested
        while (true) {
            // Step 6.1: Calculate the partition point for nums1
            //           Use (low + high) / 2 to find the middle index, rounded down
            //           Why (low + high) / 2? It directly gives the middle index of the range
            //           (e.g., low=0, high=5 -> (0+5)/2 = 2). Using (high - low) gives the
            //           range length (e.g., 5-0=5), requiring extra steps to get the index.
            //           Integer division ensures rounding down (e.g., 5/2 = 2).
            int partition_x = (low_partition_x + high_partition_x) / 2;

            // Step 6.2: Calculate the corresponding partition point for nums2
            //           The left half of the merged array has half_length elements,
            //           so partition_y = half_length - partition_x
            int partition_y = half_length - partition_x;

            // Step 6.3: Get elements around the partition for nums1
            //           - left_x: Element just before the partition in nums1
            //           - right_x: Element at or after the partition in nums1
            int left_x;
            if (partition_x == 0) {
                // If partition_x is 0, there are no elements in nums1's left half
                // Use INT_MIN to ensure any right_y is greater (valid partition)
                left_x = INT_MIN;
            } else {
                // Get the element at index partition_x - 1
                left_x = nums1[partition_x - 1];
            }

            int right_x;
            if (partition_x == size_nums1) {
                // If partition_x is at the end, there are no elements in nums1's right half
                // Use INT_MAX to ensure any left_y is smaller (valid partition)
                right_x = INT_MAX;
            } else {
                // Get the element at index partition_x
                right_x = nums1[partition_x];
            }

            // Step 6.4: Get elements around the partition for nums2
            //           - left_y: Element just before the partition in nums2
            //           - right_y: Element at or after the partition in nums2
            int left_y;
            if (partition_y == 0) {
                // If partition_y is 0, there are no elements in nums2's left half
                left_y = INT_MIN;
            } else {
                // Get the element at index partition_y - 1
                left_y = nums2[partition_y - 1];
            }

            int right_y;
            if (partition_y == size_nums2) {
                // If partition_y is at the end, there are no elements in nums2's right half
                right_y = INT_MAX;
            } else {
                // Get the element at index partition_y
                right_y = nums2[partition_y];
            }

            // Step 6.5: Check if the partition is correct
            //           A valid partition satisfies:
            //           - left_x <= right_y (elements in left half of nums1 are <= right half of nums2)
            //           - left_y <= right_x (elements in left half of nums2 are <= right half of nums1)
            if (left_x <= right_y && left_y <= right_x) {
                // Step 6.6: Partition is correct, compute the median
                if (total_length % 2 == 1) {
                    // Odd total length: Median is the maximum of the left half elements
                    int max_left = max(left_x, left_y);
                    // Debug print
                    // cout << "Found median (odd): partition_x=" << partition_x
                    //      << ", partition_y=" << partition_y << ", max_left=" << max_left << endl;
                    return max_left;
                } else {
                    // Even total length: Median is the average of the max of left half
                    // and min of right half
                    int max_left = max(left_x, left_y);
                    int min_right = min(right_x, right_y);
                    double average = (max_left + min_right) / 2.0;
                    // Debug print
                    // cout << "Found median (even): partition_x=" << partition_x
                    //      << ", partition_y=" << partition_y << ", max_left=" << max_left
                    //      << ", min_right=" << min_right << ", average=" << average << endl;
                    return average;
                }
            } else if (left_x > right_y) {
                // Step 6.7: Partition incorrect: left_x too large, move high pointer left
                //           Reduce partition_x to include fewer elements in nums1's left half
                high_partition_x = partition_x - 1;
            } else {
                // Step 6.8: Partition incorrect: left_y too large, move low pointer right
                //           Increase partition_x to include more elements in nums1's left half
                low_partition_x = partition_x + 1;
            }

            // Step 6.9: Check if binary search range is exhausted
            //           If low > high, no valid partition exists (should not happen per constraints)
            if (low_partition_x > high_partition_x) {
                // Debug print
                // cout << "No valid partition found, returning 0.0" << endl;
                return 0.0;
            }
        }

        // Step 7: Fallback return (should not reach here due to constraints)
        //         Included for completeness
        return 0.0;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (nums1 = [1,3], nums2 = [2])
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    cout << "Test Case 1: nums1 = ";
    printVector(nums1_1);
    cout << ", nums2 = ";
    printVector(nums2_1);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_1, nums2_1) << endl;

    // Test Case 2: Example from problem (nums1 = [1,2], nums2 = [3,4])
    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Test Case 2: nums1 = ";
    printVector(nums2_2);
    cout << ", nums2 = ";
    printVector(nums2_2);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_2, nums2_2) << endl;

    // Test Case 3: One empty array (nums1 = [], nums2 = [1])
    vector<int> nums1_3 = {};
    vector<int> nums2_3 = {1};
    cout << "Test Case 3: nums1 = ";
    printVector(nums1_3);
    cout << ", nums2 = ";
    printVector(nums2_3);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_3, nums2_3) << endl;

    // Test Case 4: Arrays of different lengths (nums1 = [1,2,3], nums2 = [4])
    vector<int> nums1_4 = {1, 2, 3};
    vector<int> nums2_4 = {4};
    cout << "Test Case 4: nums1 = ";
    printVector(nums1_4);
    cout << ", nums2 = ";
    printVector(nums2_4);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_4, nums2_4) << endl;

    // Test Case 5: Negative numbers (nums1 = [-2,-1], nums2 = [1,2])
    vector<int> nums1_5 = {-2, -1};
    vector<int> nums2_5 = {1, 2};
    cout << "Test Case 5: nums1 = ";
    printVector(nums1_5);
    cout << ", nums2 = ";
    printVector(nums2_5);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_5, nums2_5) << endl;

    // Test Case 6: Longer arrays (nums1 = [1,2,3,4,5,6], nums2 = [2,3,4,5,6,7,8,9])
    vector<int> nums1_6 = {1, 2, 3, 4, 5, 6};
    vector<int> nums2_6 = {2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Test Case 6: nums1 = ";
    printVector(nums1_6);
    cout << ", nums2 = ";
    printVector(nums2_6);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_6, nums2_6) << endl;

    // Test Case 7: Single element in nums1 (nums1 = [10], nums2 = [2,3,4,5,6,7])
    vector<int> nums1_7 = {10};
    vector<int> nums2_7 = {2, 3, 4, 5, 6, 7};
    cout << "Test Case 7: nums1 = ";
    printVector(nums1_7);
    cout << ", nums2 = ";
    printVector(nums2_7);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_7, nums2_7) << endl;

    return 0;
}