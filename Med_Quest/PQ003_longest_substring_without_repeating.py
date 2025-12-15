# LeetCode Problem 3: Longest Substring Without Repeating Characters
# Difficulty: Medium
# Description: Given a string s, find the length of the longest substring without repeating characters.
# Constraints:
#   - 0 <= s.length <= 5 * 10^4
#   - s consists of English letters, digits, symbols, and spaces
# Algorithmic Pattern: Sliding Window
#   - Use a sliding window with two pointers (left and right) and a set to track characters in the current window.
#     Expand the right pointer and add characters to the set. If a duplicate is found, shrink the window from the left
#     until the duplicate is removed. Track the maximum length. Achieves O(n) time and O(min(n, charset)) space.

from typing import List

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Returns the length of the longest substring without repeating characters.
        """
        # ------------------------------
        # BEGIN YOUR CODE HERE
        # ------------------------------

        # Step 1: Get the length of the input string
        string_length = len(s)

        # Step 2: Handle edge case: if string is empty, return 0
        if string_length == 0:
            return 0

        # Step 3: Initialize variables for the sliding window
        left_pointer = 0
        max_length = 0
        current_characters = set()  # Set to store unique characters in the current window

        # Step 4: Iterate through the string with the right pointer
        for right_pointer in range(string_length):
            # Step 4.1: Get the current character
            current_char = s[right_pointer]

            # Step 4.2: Shrink the window from the left if the character is already in the set
            while current_char in current_characters:
                # Remove the leftmost character from the set
                left_char = s[left_pointer]
                current_characters.remove(left_char)
                # Move the left pointer right
                left_pointer += 1

            # Step 4.3: Add the current character to the set
            current_characters.add(current_char)

            # Step 4.4: Calculate the current window length
            current_length = right_pointer - left_pointer + 1

            # Step 4.5: Update max_length if current window is longer
            if current_length > max_length:
                max_length = current_length

            # Debug print (commented out)
            # print(f"Right: {right_pointer}, Char: {current_char}, Left: {left_pointer}, "
            #       f"Current Length: {current_length}, Max Length: {max_length}")

        # Step 5: Return the maximum length found
        return max_length

        # ------------------------------
        # END YOUR CODE HERE
        # ------------------------------

def main():
    solution = Solution()

    # Test Case 1: Example from problem (s = "abcabcbb")
    s_1 = "abcabcbb"
    print(f"Test Case 1: s = \"{s_1}\" -> Length: {solution.lengthOfLongestSubstring(s_1)}")

    # Test Case 2: Example from problem (s = "bbbbb")
    s_2 = "bbbbb"
    print(f"Test Case 2: s = \"{s_2}\" -> Length: {solution.lengthOfLongestSubstring(s_2)}")

    # Test Case 3: Example from problem (s = "pwwkew")
    s_3 = "pwwkew"
    print(f"Test Case 3: s = \"{s_3}\" -> Length: {solution.lengthOfLongestSubstring(s_3)}")

    # Test Case 4: Empty string (s = "")
    s_4 = ""
    print(f"Test Case 4: s = \"{s_4}\" -> Length: {solution.lengthOfLongestSubstring(s_4)}")

    # Test Case 5: Single character (s = "a")
    s_5 = "a"
    print(f"Test Case 5: s = \"{s_5}\" -> Length: {solution.lengthOfLongestSubstring(s_5)}")

    # Test Case 6: All unique characters (s = "abcdef")
    s_6 = "abcdef"
    print(f"Test Case 6: s = \"{s_6}\" -> Length: {solution.lengthOfLongestSubstring(s_6)}")

    # Test Case 7: Spaces and symbols (s = "au ")
    s_7 = "au "
    print(f"Test Case 7: s = \"{s_7}\" -> Length: {solution.lengthOfLongestSubstring(s_7)}")

    # Test Case 8: Long string with repeating pattern (s = "dvdf")
    s_8 = "dvdf"
    print(f"Test Case 8: s = \"{s_8}\" -> Length: {solution.lengthOfLongestSubstring(s_8)}")

if __name__ == "__main__":
    main()