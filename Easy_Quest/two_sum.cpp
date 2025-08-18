// LeetCode: 1. Two Sum
// Description:
// Given an array of integers nums and an integer target, return indices of the two
// numbers such that they add up to target. You may assume that each input would have
// exactly one solution, and you may not use the same element twice. You can return
// the answer in any order.
//
// Constraints:
// - 2 <= nums.length <= 10^4
// - -10^9 <= nums[i] <= 10^9
// - -10^9 <= target <= 10^9
// - Only one valid answer exists.
//
// Test Cases:
// 1. Input: nums = [2,7,11,15], target = 9
//    Output: [0,1] (Explanation: nums[0] + nums[1] = 2 + 7 = 9)
// 2. Input: nums = [3,2,4], target = 6
//    Output: [1,2] (Explanation: nums[1] + nums[2] = 2 + 4 = 6)
// 3. Input: nums = [3,3], target = 6
//    Output: [0,1] (Explanation: nums[0] + nums[1] = 3 + 3 = 6)

#include <vector>            // For std::vector
#include <unordered_map>     // For std::unordered_map
#include <iostream>          // For std::cout

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Hashmap to store number-to-index mappings
        unordered_map<int, int> numMap;
        int complement;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement needed to reach target
            complement = target - nums[i];

            // Check if complement exists in hashmap
            if (numMap.find(complement) != numMap.end()) {
                // Return indices of complement and current number
                return {numMap[complement], i};
            }

            // Store current number and its index
            numMap[nums[i]] = i;
        }

        // Return empty vector (though problem guarantees a solution)
        return {};

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/

    }
};

int main() {
    // Create Solution object
    Solution sol;

    // Test case 1: nums = [2,7,11,15], target = 9
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) cout << ",";
    }
    cout << "], target = " << target1 << ", Output: [" << result1[0] << "," << result1[1] << "]" << endl;

    // Test case 2: nums = [3,2,4], target = 6
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1) cout << ",";
    }
    cout << "], target = " << target2 << ", Output: [" << result2[0] << "," << result2[1] << "]" << endl;

    // Test case 3: nums = [3,3], target = 6
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums3.size(); i++) {
        cout << nums3[i];
        if (i < nums3.size() - 1) cout << ",";
    }
    cout << "], target = " << target3 << ", Output: [" << result3[0] << "," << result3[1] << "]" << endl;

    return 0;
}
