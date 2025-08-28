// LeetCode Problem 136: Single Number
// Difficulty: Easy
// Description: Given a non-empty array of integers nums, every element appears twice
//              except for one. Find that single number.
// Constraints:
//   - 1 <= nums.length <= 3 * 10^4
//   - -3 * 10^4 <= nums[i] <= 3 * 10^4
//   - Each element in the array appears twice except for one element which appears once.
// Algorithmic Pattern: Bit Manipulation
//   - The solution uses the bitwise XOR operation to find the single number. Since
//     XORing a number with itself yields 0 and XORing with 0 yields the number,
//     all paired numbers cancel out, leaving the single number. Achieves O(n) time
//     and O(1) space.

#include <vector>
#include <iostream>

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
    int singleNumber(vector<int>& nums) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Initialize result to store XOR of all elements
        int xor_result = 0;

        // Iterate through each element in the array
        for (int current_num : nums) {
            // XOR with current number
            xor_result ^= current_num;
            // Debug print (commented out)
            // cout << "Current num: " << current_num << ", XOR result: " << xor_result << endl;
        }

        // Return the single number
        return xor_result;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (nums = [2,2,1])
    vector<int> nums_1 = {2, 2, 1};
    cout << "Test Case 1: nums = ";
    printVector(nums_1);
    cout << " -> Single Number: ";
    cout << solution.singleNumber(nums_1) << endl;

    // Test Case 2: Example from problem (nums = [4,1,2,1,2])
    vector<int> nums_2 = {4, 1, 2, 1, 2};
    cout << "Test Case 2: nums = ";
    printVector(nums_2);
    cout << " -> Single Number: ";
    cout << solution.singleNumber(nums_2) << endl;

    // Test Case 3: Single element (nums = [5])
    vector<int> nums_3 = {5};
    cout << "Test Case 3: nums = ";
    printVector(nums_3);
    cout << " -> Single Number: ";
    cout << solution.singleNumber(nums_3) << endl;

    // Test Case 4: Negative numbers (nums = [-3,-3,7,7,-1])
    vector<int> nums_4 = {-3, -3, 7, 7, -1};
    cout << "Test Case 4: nums = ";
    printVector(nums_4);
    cout << " -> Single Number: ";
    cout << solution.singleNumber(nums_4) << endl;

    // Test Case 5: Large numbers (nums = [10000,10000,20000,20000,12345])
    vector<int> nums_5 = {10000, 10000, 20000, 20000, 12345};
    cout << "Test Case 5: nums = ";
    printVector(nums_5);
    cout << " -> Single Number: ";
    cout << solution.singleNumber(nums_5) << endl;

    // Test Case 6: Mixed numbers (nums = [0,0,1,1,999])
    vector<int> nums_6 = {0, 0, 1, 1, 999};
    cout << "Test Case 6: nums = ";
    printVector(nums_6);
    cout << " -> Single Number: ";
    cout << solution.singleNumber(nums_6) << endl;

    return 0;
}