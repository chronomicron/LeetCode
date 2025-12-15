# LeetCode Problem 1: Two Sum
# Difficulty: Easy
# Description: Given an array of integers nums and an integer target, return the indices
#              of the two numbers such that they add up to target. Assume exactly one solution
#              exists, and you may not use the same element twice. Return indices in any order.
# Constraints:
#   - 2 <= nums.length <= 10^4
#   - -10^9 <= nums[i] <= 10^9
#   - -10^9 <= target <= 10^9
#   - Only one valid answer exists
# Algorithmic Pattern: Hash Map
#   - Use a dictionary to store seen numbers and their indices. For each number, check if
#     (target - number) exists in the map. Achieves O(n) time and O(n) space.

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Returns the indices of the two numbers that add up to target.
        """
        # ------------------------------
        # BEGIN YOUR CODE HERE
        # ------------------------------

        # Step 1: Initialize a dictionary to store seen numbers and their indices
        seen_numbers = {}

        # Step 2: Iterate through the array with index and value
        for current_index in range(len(nums)):
            # Step 2.1: Get the current number
            current_number = nums[current_index]

            # Step 2.2: Calculate the complement needed to reach target
            complement = target - current_number

            # Step 2.3: Check if the complement is in the dictionary
            if complement in seen_numbers:
                # Found the pair, return their indices
                return [seen_numbers[complement], current_index]

            # Step 2.4: Add the current number and its index to the dictionary
            seen_numbers[current_number] = current_index

        # Step 3: If no solution found (should not happen per constraints), return empty list
        return []

        # ------------------------------
        # END YOUR CODE HERE
        # ------------------------------

def main():
    solution = Solution()

    # Test Case 1: Example from problem (nums = [2,7,11,15], target = 9)
    nums_1 = [2, 7, 11, 15]
    target_1 = 9
    print(f"Test Case 1: nums = {nums_1}, target = {target_1} -> Indices: {solution.twoSum(nums_1, target_1)}")

    # Test Case 2: Example from problem (nums = [3,2,4], target = 6)
    nums_2 = [3, 2, 4]
    target_2 = 6
    print(f"Test Case 2: nums = {nums_2}, target = {target_2} -> Indices: {solution.twoSum(nums_2, target_2)}")

    # Test Case 3: Example from problem (nums = [3,3], target = 6)
    nums_3 = [3, 3]
    target_3 = 6
    print(f"Test Case 3: nums = {nums_3}, target = {target_3} -> Indices: {solution.twoSum(nums_3, target_3)}")

    # Test Case 4: Minimum length array (nums = [1,2], target = 3)
    nums_4 = [1, 2]
    target_4 = 3
    print(f"Test Case 4: nums = {nums_4}, target = {target_4} -> Indices: {solution.twoSum(nums_4, target_4)}")

    # Test Case 5: Negative numbers (nums = [-1,-2,-3,-4,-5], target = -8)
    nums_5 = [-1, -2, -3, -4, -5]
    target_5 = -8
    print(f"Test Case 5: nums = {nums_5}, target = {target_5} -> Indices: {solution.twoSum(nums_5, target_5)}")

    # Test Case 6: Large numbers (nums = [1000000000, -1000000000], target = 0)
    nums_6 = [1000000000, -1000000000]
    target_6 = 0
    print(f"Test Case 6: nums = {nums_6}, target = {target_6} -> Indices: {solution.twoSum(nums_6, target_6)}")

    # Test Case 7: Duplicate numbers but different indices (nums = [5,5,5,5], target = 10)
    nums_7 = [5, 5, 5, 5]
    target_7 = 10
    print(f"Test Case 7: nums = {nums_7}, target = {target_7} -> Indices: {solution.twoSum(nums_7, target_7)}")

if __name__ == "__main__":
    main()
    