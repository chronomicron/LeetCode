// LeetCode Problem 15: 3Sum
// Difficulty: Medium
// Description: Given an integer array nums, find all unique triplets [nums[i], nums[j], nums[k]]
//              where i != j, i != k, j != k, and nums[i] + nums[j] + nums[k] == 0.
//              Return the triplets in any order, ensuring no duplicates.
// Constraints:
//   - 3 <= nums.length <= 3000
//   - -10^5 <= nums[i] <= 10^5
// Algorithmic Pattern: Two Pointers + Sorting
//   - Sort the array and use a two-pointer technique for each fixed element to find pairs
//     summing to the negative of the fixed element. Skip duplicates to ensure uniqueness.
//     Achieves O(n²) time and O(1) space (excluding sorting and output).

#include <vector>
#include <iostream>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Initialize the result vector to store triplets
        vector<vector<int>> result_triplets;

        // Step 2: Handle edge case: if array has fewer than 3 elements, return empty result
        if (nums.size() < 3) {
            return result_triplets;
        }

        // Step 3: Sort the array to enable two-pointer technique and handle duplicates
        sort(nums.begin(), nums.end());

        // Step 4: Iterate through each element as the first number of the triplet
        for (int i = 0; i < nums.size() - 2; i++) {
            // Step 4.1: Skip duplicate values for i to avoid duplicate triplets
            if (i > 0) {
                if (nums[i] == nums[i - 1]) {
                    continue;
                }
            }

            // Step 4.2: If current number is positive, no valid triplets possible (since sum must be 0)
            if (nums[i] > 0) {
                break;
            }

            // Step 4.3: Initialize two pointers for the remaining pair
            int left_pointer = i + 1;
            int right_pointer = nums.size() - 1;

            // Step 4.4: Use two pointers to find pairs summing to -nums[i]
            while (left_pointer < right_pointer) {
                // Step 4.4.1: Calculate the current sum
                int current_sum = nums[i] + nums[left_pointer] + nums[right_pointer];

                // Step 4.4.2: Check if sum equals 0
                if (current_sum == 0) {
                    // Found a valid triplet, add to result
                    vector<int> triplet = {nums[i], nums[left_pointer], nums[right_pointer]};
                    result_triplets.push_back(triplet);

                    // Step 4.4.3: Skip duplicate values for left_pointer
                    do {
                        left_pointer++;
                    } while (left_pointer < right_pointer && nums[left_pointer] == nums[left_pointer - 1]);

                    // Step 4.4.4: Skip duplicate values for right_pointer
                    do {
                        right_pointer--;
                    } while (left_pointer < right_pointer && nums[right_pointer] == nums[right_pointer + 1]);
                } else if (current_sum < 0) {
                    // Step 4.4.5: Sum is too small, move left pointer right
                    left_pointer++;
                } else {
                    // Step 4.4.6: Sum is too large, move right pointer left
                    right_pointer--;
                }

                // Debug print (commented out)
                // cout << "i: " << i << ", left: " << left_pointer << ", right: " << right_pointer
                //      << ", sum: " << current_sum << ", result size: " << result_triplets.size() << endl;
            }
        }

        // Step 5: Return the list of unique triplets
        return result_triplets;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

// Helper function to print vector of vectors for test output
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

int main() {
    Solution solution;

    // Test Case 1: Example from problem (nums = [-1,0,1,2,-1,-4])
    vector<int> input_1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test Case 1: nums = [-1,0,1,2,-1,-4] -> Triplets: ";
    printResult(solution.threeSum(input_1));
    cout << endl;

    // Test Case 2: Example from problem (nums = [0,1,1])
    vector<int> input_2 = {0, 1, 1};
    cout << "Test Case 2: nums = [0,1,1] -> Triplets: ";
    printResult(solution.threeSum(input_2));
    cout << endl;

    // Test Case 3: Example from problem (nums = [0,0,0])
    vector<int> input_3 = {0, 0, 0};
    cout << "Test Case 3: nums = [0,0,0] -> Triplets: ";
    printResult(solution.threeSum(input_3));
    cout << endl;

    // Test Case 4: No triplets (nums = [1,2,3,4])
    vector<int> input_4 = {1, 2, 3, 4};
    cout << "Test Case 4: nums = [1,2,3,4] -> Triplets: ";
    printResult(solution.threeSum(input_4));
    cout << endl;

    // Test Case 5: Multiple zeros (nums = [0,0,0,0,0])
    vector<int> input_5 = {0, 0, 0, 0, 0};
    cout << "Test Case 5: nums = [0,0,0,0,0] -> Triplets: ";
    printResult(solution.threeSum(input_5));
    cout << endl;

    // Test Case 6: Large numbers (nums = [-2,-1,0,1,2,3,-3])
    vector<int> input_6 = {-2, -1, 0, 1, 2, 3, -3};
    cout << "Test Case 6: nums = [-2,-1,0,1,2,3,-3] -> Triplets: ";
    printResult(solution.threeSum(input_6));
    cout << endl;

    // Test Case 7: Minimum length (nums = [-1,0,1])
    vector<int> input_7 = {-1, 0, 1};
    cout << "Test Case 7: nums = [-1,0,1] -> Triplets: ";
    printResult(solution.threeSum(input_7));
    cout << endl;

    // Test Case 8: All negative numbers (nums = [-4,-3,-2,-1,-1])
    vector<int> input_8 = {-4, -3, -2, -1, -1};
    cout << "Test Case 8: nums = [-4,-3,-2,-1,-1] -> Triplets: ";
    printResult(solution.threeSum(input_8));
    cout << endl;

    return 0;
}
