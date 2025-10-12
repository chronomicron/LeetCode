// LeetCode Problem 18: 4Sum
// Difficulty: Medium
// Description: Given an integer array nums and a target integer, find all unique quadruplets
//              [nums[a], nums[b], nums[c], nums[d]] where a, b, c, d are distinct indices
//              and nums[a] + nums[b] + nums[c] + nums[d] == target. Return in any order.
// Constraints:
//   - 1 <= nums.length <= 200
//   - -10^9 <= nums[i], target <= 10^9
// Algorithmic Pattern: Two Pointers + Sorting
//   - Sort the array, fix two numbers with nested loops, and use two pointers to find the
//     remaining two numbers summing to target - nums[i] - nums[j]. Skip duplicates.
//     Achieves O(n³) time and O(1) space (excluding sorting and output).

#include <vector>
#include <iostream>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Initialize the result vector to store quadruplets
        vector<vector<int>> result_quadruplets;

        // Step 2: Handle edge case: if array has fewer than 4 elements, return empty result
        if (nums.size() < 4) {
            return result_quadruplets;
        }

        // Step 3: Sort the array to enable two-pointer technique and handle duplicates
        sort(nums.begin(), nums.end());

        // Step 4: Iterate through each element as the first number of the quadruplet
        for (int i = 0; i < nums.size() - 3; i++) {
            // Step 4.1: Skip duplicate values for i to avoid duplicate quadruplets
            if (i > 0) {
                if (nums[i] == nums[i - 1]) {
                    continue;
                }
            }

            // Step 4.2: Early termination: if smallest sum exceeds target, break
            if (static_cast<long>(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]) > target) {
                break;
            }

            // Step 4.3: Early termination: if largest sum is less than target, skip
            if (static_cast<long>(nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1]) < target) {
                continue;
            }

            // Step 4.4: Iterate through each element as the second number
            for (int j = i + 1; j < nums.size() - 2; j++) {
                // Step 4.4.1: Skip duplicate values for j
                if (j > i + 1) {
                    if (nums[j] == nums[j - 1]) {
                        continue;
                    }
                }

                // Step 4.4.2: Early termination: if smallest sum exceeds target, break
                if (static_cast<long>(nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target) {
                    break;
                }

                // Step 4.4.3: Early termination: if largest sum is less than target, skip
                if (static_cast<long>(nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1]) < target) {
                    continue;
                }

                // Step 4.4.4: Initialize two pointers for the remaining pair
                int left_pointer = j + 1;
                int right_pointer = nums.size() - 1;

                // Step 4.4.5: Use two pointers to find pairs summing to target - nums[i] - nums[j]
                while (left_pointer < right_pointer) {
                    // Step 4.4.5.1: Calculate the current sum (use long to avoid overflow)
                    long current_sum = static_cast<long>(nums[i]) + nums[j] + nums[left_pointer] + nums[right_pointer];

                    // Step 4.4.5.2: Check if sum equals target
                    if (current_sum == target) {
                        // Found a valid quadruplet, add to result
                        vector<int> quadruplet = {nums[i], nums[j], nums[left_pointer], nums[right_pointer]};
                        result_quadruplets.push_back(quadruplet);

                        // Step 4.4.5.3: Skip duplicate values for left_pointer
                        do {
                            left_pointer++;
                        } while (left_pointer < right_pointer && nums[left_pointer] == nums[left_pointer - 1]);

                        // Step 4.4.5.4: Skip duplicate values for right_pointer
                        do {
                            right_pointer--;
                        } while (left_pointer < right_pointer && nums[right_pointer] == nums[right_pointer + 1]);
                    } else if (current_sum < target) {
                        // Step 4.4.5.5: Sum is too small, move left pointer right
                        left_pointer++;
                    } else {
                        // Step 4.4.5.6: Sum is too large, move right pointer left
                        right_pointer--;
                    }

                    // Debug print (commented out)
                    // cout << "i: " << i << ", j: " << j << ", left: " << left_pointer
                    //      << ", right: " << right_pointer << ", sum: " << current_sum << endl;
                }
            }
        }

        // Step 5: Return the list of unique quadruplets
        return result_quadruplets;

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

    // Test Case 1: Example from problem (nums = [1,0,-1,0,-2,2], target = 0)
    vector<int> input_1 = {1, 0, -1, 0, -2, 2};
    int target_1 = 0;
    cout << "Test Case 1: nums = [1,0,-1,0,-2,2], target = " << target_1 << " -> Quadruplets: ";
    printResult(solution.fourSum(input_1, target_1));
    cout << endl;

    // Test Case 2: Example from problem (nums = [2,2,2,2,2], target = 8)
    vector<int> input_2 = {2, 2, 2, 2, 2};
    int target_2 = 8;
    cout << "Test Case 2: nums = [2,2,2,2,2], target = " << target_2 << " -> Quadruplets: ";
    printResult(solution.fourSum(input_2, target_2));
    cout << endl;

    // Test Case 3: Minimum length (nums = [1,2,3,4], target = 10)
    vector<int> input_3 = {1, 2, 3, 4};
    int target_3 = 10;
    cout << "Test Case 3: nums = [1,2,3,4], target = " << target_3 << " -> Quadruplets: ";
    printResult(solution.fourSum(input_3, target_3));
    cout << endl;

    // Test Case 4: No quadruplets (nums = [1,2,3,4], target = 20)
    vector<int> input_4 = {1, 2, 3, 4};
    int target_4 = 20;
    cout << "Test Case 4: nums = [1,2,3,4], target = " << target_4 << " -> Quadruplets: ";
    printResult(solution.fourSum(input_4, target_4));
    cout << endl;

    // Test Case 5: Large numbers (nums = [-1000000000,0,0,1000000000], target = 0)
    vector<int> input_5 = {-1000000000, 0, 0, 1000000000};
    int target_5 = 0;
    cout << "Test Case 5: nums = [-1000000000,0,0,1000000000], target = " << target_5 << " -> Quadruplets: ";
    printResult(solution.fourSum(input_5, target_5));
    cout << endl;

    // Test Case 6: All zeros (nums = [0,0,0,0], target = 0)
    vector<int> input_6 = {0, 0, 0, 0};
    int target_6 = 0;
    cout << "Test Case 6: nums = [0,0,0,0], target = " << target_6 << " -> Quadruplets: ";
    printResult(solution.fourSum(input_6, target_6));
    cout << endl;

    return 0;
}
