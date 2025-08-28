// LeetCode Problem 4: Median of Two Sorted Arrays
// Difficulty: Hard
// Description: Given two sorted arrays nums1 and nums2 of size m and n respectively,
//              return the median of the two sorted arrays. The overall run time
//              complexity should be O(log(m+n)).
// Constraints:
//   - nums1.length == m
//   - nums2.length == n
//   - 0 <= m <= 1000
//   - 0 <= n <= 1000
//   - 1 <= m + n <= 2000
//   - -10^6 <= nums1[i], nums2[i] <= 10^6
// Algorithmic Pattern: Modified Binary Search
//   - The solution uses a binary search to find the correct partition point between
//     the two sorted arrays, ensuring the left and right halves satisfy the median
//     condition in O(log(min(m,n))) time, which satisfies O(log(m+n)).

#include <vector>
#include <iostream>
#include <climits>

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

        // Get sizes of input arrays
        int size_nums1 = nums1.size();
        int size_nums2 = nums2.size();

        // Ensure nums1 is the smaller array to minimize binary search range
        if (size_nums1 > size_nums2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Total length of merged array
        int total_length = size_nums1 + size_nums2;
        // Half length for partitioning (use integer division for floor)
        int half_length = (total_length + 1) / 2;

        // Binary search boundaries for nums1
        int left_partition_x = 0;
        int right_partition_x = size_nums1;

        while (left_partition_x <= right_partition_x) {
            // Middle partition point for nums1
            int partition_x = (left_partition_x + right_partition_x) / 2;
            // Corresponding partition point for nums2
            int partition_y = half_length - partition_x;

            // Get left and right elements around the partition for nums1
            int left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
            int right_x = (partition_x == size_nums1) ? INT_MAX : nums1[partition_x];

            // Get left and right elements around the partition for nums2
            int left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];
            int right_y = (partition_y == size_nums2) ? INT_MAX : nums2[partition_y];

            // Check if partition is correct (left_x <= right_y and left_y <= right_x)
            if (left_x <= right_y && left_y <= right_x) {
                // If total length is odd, median is max of left elements
                if (total_length % 2 == 1) {
                    return max(left_x, left_y);
                }
                // If total length is even, median is average of max(left) and min(right)
                return (max(left_x, left_y) + min(right_x, right_y)) / 2.0;
            }
            // Adjust binary search: move left if left_x > right_y, else move right
            else if (left_x > right_y) {
                right_partition_x = partition_x - 1;
            }
            else {
                left_partition_x = partition_x + 1;
            }
        }

        // If no valid partition is found, input is invalid (should not happen per constraints)
        return 0.0;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: nums1 = [1,3], nums2 = [2]
    vector<int> nums1_1 = {1, 3};
    vector<int> nums2_1 = {2};
    cout << "Test Case 1: nums1 = ";
    printVector(nums1_1);
    cout << ", nums2 = ";
    printVector(nums2_1);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_1, nums2_1) << endl;

    // Test Case 2: nums1 = [1,2], nums2 = [3,4]
    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Test Case 2: nums1 = ";
    printVector(nums1_2);
    cout << ", nums2 = ";
    printVector(nums2_2);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_2, nums2_2) << endl;

    // Test Case 3: nums1 = [], nums2 = [1]
    vector<int> nums1_3 = {};
    vector<int> nums2_3 = {1};
    cout << "Test Case 3: nums1 = ";
    printVector(nums1_3);
    cout << ", nums2 = ";
    printVector(nums2_3);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_3, nums2_3) << endl;

    // Test Case 4: nums1 = [1,2,3], nums2 = [4]
    vector<int> nums1_4 = {1, 2, 3};
    vector<int> nums2_4 = {4};
    cout << "Test Case 4: nums1 = ";
    printVector(nums1_4);
    cout << ", nums2 = ";
    printVector(nums2_4);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_4, nums2_4) << endl;

    // Test Case 5: nums1 = [-2,-1], nums2 = [1,2]
    vector<int> nums1_5 = {-2, -1};
    vector<int> nums2_5 = {1, 2};
    cout << "Test Case 5: nums1 = ";
    printVector(nums1_5);
    cout << ", nums2 = ";
    printVector(nums2_5);
    cout << " -> Median: ";
    cout << solution.findMedianSortedArrays(nums1_5, nums2_5) << endl;

    return 0;
}