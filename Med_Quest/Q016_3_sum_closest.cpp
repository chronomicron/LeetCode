// LeetCode Problem 16: 3Sum Closest
// Difficulty: Medium
// Description: Given an integer array nums and a target integer, find three integers
//              whose sum is closest to target. Return the sum. Assume exactly one solution.
// Constraints:
//   - 3 <= nums.length <= 500
//   - -1000 <= nums[i] <= 1000
//   - -10^4 <= target <= 10^4
// Algorithmic Pattern: Two Pointers + Sorting
//   - Sort the array and use a two-pointer technique for each fixed element to find
//     pairs summing closest to target - nums[i]. Track the closest sum. Achieves
//     O(n²) time and O(1) space (excluding sorting).

#include <vector>
#include <iostream>
#include <algorithm> // For sort
#include <cstdlib> // For abs

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Initialize the closest sum (use first possible triplet as initial value)
        int closest_sum = nums[0] + nums[1] + nums[2];
        int array_length = nums.size();

        // Step 2: Sort the array to enable two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 3: Iterate through each element as the first number of the triplet
        for (int i = 0; i < array_length - 2; i++) {
            // Step 3.1: Initialize two pointers for the remaining pair
            int left_pointer = i + 1;
            int right_pointer = array_length - 1;

            // Step 3.2: Use two pointers to find pairs summing with nums[i]
            while (left_pointer < right_pointer) {
                // Step 3.2.1: Calculate the current sum
                int current_sum = nums[i] + nums[left_pointer] + nums[right_pointer];

                // Step 3.2.2: If current sum equals target, return immediately
                if (current_sum == target) {
                    return current_sum;
                }

                // Step 3.2.3: Update closest_sum if current_sum is closer to target
                int current_diff = abs(current_sum - target);
                int closest_diff = abs(closest_sum - target);
                if (current_diff < closest_diff) {
                    closest_sum = current_sum;
                }

                // Step 3.2.4: Adjust pointers based on sum
                if (current_sum < target) {
                    // Sum is too small, move left pointer right
                    left_pointer++;
                } else {
                    // Sum is too large, move right pointer left
                    right_pointer--;
                }

                // Debug print (commented out)
                // cout << "i: " << i << ", left: " << left_pointer << ", right: " << right_pointer
                //      << ", sum: " << current_sum << ", closest: " << closest_sum << endl;
            }
        }

        // Step 4: Return the closest sum found
        return closest_sum;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (nums = [-1,2,1,-4], target = 1)
    vector<int> input_1 = {-1, 2, 1, -4};
    int target_1 = 1;
    cout << "Test Case 1: nums = [-1,2,1,-4], target = " << target_1 << " -> Closest Sum: ";
    cout << solution.threeSumClosest(input_1, target_1) << endl;

    // Test Case 2: Example from problem (nums = [0,0,0], target = 1)
    vector<int> input_2 = {0, 0, 0};
    int target_2 = 1;
    cout << "Test Case 2: nums = [0,0,0], target = " << target_2 << " -> Closest Sum: ";
    cout << solution.threeSumClosest(input_2, target_2) << endl;

    // Test Case 3: All zeros, negative target (nums = [0,0,0], target = -1)
    vector<int> input_3 = {0, 0, 0};
    int target_3 = -1;
    cout << "Test Case 3: nums = [0,0,0], target = " << target_3 << " -> Closest Sum: ";
    cout << solution.threeSumClosest(input_3, target_3) << endl;

    // Test Case 4: Large numbers (nums = [100,200,-300,-400], target = 0)
    vector<int> input_4 = {100, 200, -300, -400};
    int target_4 = 0;
    cout << "Test Case 4: nums = [100,200,-300,-400], target = " << target_4 << " -> Closest Sum: ";
    cout << solution.threeSumClosest(input_4, target_4) << endl;

    // Test Case 5: Minimum length (nums = [1,2,-3], target = 0)
    vector<int> input_5 = {1, 2, -3};
    int target_5 = 0;
    cout << "Test Case 5: nums = [1,2,-3], target = " << target_5 << " -> Closest Sum: ";
    cout << solution.threeSumClosest(input_5, target_5) << endl;

    // Test Case 6: Duplicate numbers (nums = [1,1,1,1], target = 2)
    vector<int> input_6 = {1, 1, 1, 1};
    int target_6 = 2;
    cout << "Test Case 6: nums = [1,1,1,1], target = " << target_6 << " -> Closest Sum: ";
    cout << solution.threeSumClosest(input_6, target_6) << endl;

    return 0;
}