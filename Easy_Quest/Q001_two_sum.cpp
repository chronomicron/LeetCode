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

#include <iostream>

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        vector<int> solution = {};
        unordered_map<int, int> remainder_map;
        int remainder = 0;

        for (int i = 0; i < nums.size(); i++){

            // Calculate the remainder needed to reach target
            remainder = target - nums[i];

            // Check if remainder exists in hashmap
            if(!remainder_map.count(remainder)){
                // if remainder doesn't exist, add it, key is remainder, value is index
                remainder_map[nums[i]] = i;
            }
            else{
                // if the remainder does exist in hash map
                // return the value at key 'remainder', and current index
                solution = {remainder_map[remainder] , i};
            }

        }

        return solution;

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

    // Test case 4: nums = [25,52,24, 55, 5, 42], target = 47
    vector<int> nums4 = {25,52,24, 55, 5, 42};
    int target4 = 47;
    vector<int> result4 = sol.twoSum(nums4, target4);
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums4.size(); i++) {
        cout << nums4[i];
        if (i < nums4.size() - 1) cout << ",";
    }
    cout << "], target = " << target4 << ", Output: [" << result4[0] << "," << result4[1] << "]" << endl;

    // Test case 5: nums = [3,3], target = 6
    vector<int> nums5 = {55, 34, 65, 45, 732, 55, 666, 45, 6};
    int target5 = 40;
    vector<int> result5 = sol.twoSum(nums5, target5);
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums5.size(); i++) {
        cout << nums5[i];
        if (i < nums5.size() - 1) cout << ",";
    }
    cout << "], target = " << target5 << ", Output: [" << result5[0] << "," << result5[1] << "]" << endl;


    return 0;
}
