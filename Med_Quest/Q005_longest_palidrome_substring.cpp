// LeetCode Problem 5: Longest Palindromic Substring
// Difficulty: Medium
// Description: Given a string s, return the longest palindromic substring in s.
//              A palindrome is a string that reads the same forward and backward.
// Constraints:
//   - 1 <= s.length <= 1000
//   - s consists of only digits and lowercase English letters
// Algorithmic Pattern: Two Pointers
//   - This solution uses the traditional Two Pointers expand-around-center approach,
//     where two pointers (left and right) expand around each character (for odd-length
//     palindromes) or between characters (for even-length palindromes) to find the
//     longest palindrome. This achieves O(n²) time and O(1) space, with clear logic
//     for debugging.

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Get the length of the input string
        int string_length = s.length();

        // Step 2: Handle base cases: if string is empty, return empty string
        if (string_length == 0) {
            return "";
        }

        // Step 3: Initialize variables to track the longest palindrome
        int max_palindrome_start = 0; // Starting index of the longest palindrome
        int max_palindrome_length = 1; // Length of the longest palindrome (minimum 1 for single character)

        // Step 4: Iterate through each position in the string as a potential center
        for (int center_index = 0; center_index < string_length; center_index++) {
            // Step 4.1: Check odd-length palindrome centered at center_index
            int left_pointer = center_index;
            int right_pointer = center_index;
            int current_length = 1; // Single character is always a palindrome

            // Step 4.2: Expand around the center while characters match and within bounds
            while (left_pointer - 1 >= 0 && right_pointer + 1 < string_length &&
                   s[left_pointer - 1] == s[right_pointer + 1]) {
                left_pointer--;
                right_pointer++;
                current_length += 2;

                // Debug print for odd-length expansion
                // cout << "Odd: center=" << center_index << ", left=" << left_pointer
                //      << ", right=" << right_pointer << ", len=" << current_length << endl;
            }

            // Step 4.3: Update longest palindrome if current is longer
            if (current_length > max_palindrome_length) {
                max_palindrome_start = left_pointer;
                max_palindrome_length = current_length;
            }

            // Step 4.4: Check even-length palindrome centered between center_index and center_index + 1
            if (center_index + 1 < string_length && s[center_index] == s[center_index + 1]) {
                left_pointer = center_index;
                right_pointer = center_index + 1;
                current_length = 2; // Two adjacent characters form a palindrome

                // Step 4.5: Expand around the center while characters match and within bounds
                while (left_pointer - 1 >= 0 && right_pointer + 1 < string_length &&
                       s[left_pointer - 1] == s[right_pointer + 1]) {
                    left_pointer--;
                    right_pointer++;
                    current_length += 2;

                    // Debug print for even-length expansion
                    // cout << "Even: center=" << center_index << ", left=" << left_pointer
                    //      << ", right=" << right_pointer << ", len=" << current_length << endl;
                }

                // Step 4.6: Update longest palindrome if current is longer
                if (current_length > max_palindrome_length) {
                    max_palindrome_start = left_pointer;
                    max_palindrome_length = current_length;
                }
            }
        }

        // Step 5: Extract and return the longest palindrome substring
        string longest_palindrome_substring = s.substr(max_palindrome_start, max_palindrome_length);
        return longest_palindrome_substring;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (s = "babad")
    string input_1 = "babad";
    cout << "Test Case 1: s = ";
    cout << input_1;
    cout << " -> Longest Palindrome: ";
    cout << solution.longestPalindrome(input_1) << endl;

    // Test Case 2: Example from problem (s = "cbbd")
    string input_2 = "cbbd";
    cout << "Test Case 2: s = ";
    cout << input_2;
    cout << " -> Longest Palindrome: ";
    cout << solution.longestPalindrome(input_2) << endl;

    // Test Case 3: Long repetitive string (s = "aaaaaaa")
    string input_3 = "aaaaaaa";
    cout << "Test Case 3: s = ";
    cout << input_3;
    cout << " -> Longest Palindrome: ";
    cout << solution.longestPalindrome(input_3) << endl;

    // Test Case 4: Single character (s = "a")
    string input_4 = "a";
    cout << "Test Case 4: s = ";
    cout << input_4;
    cout << " -> Longest Palindrome: ";
    cout << solution.longestPalindrome(input_4) << endl;

    // Test Case 5: No palindrome longer than 1 (s = "abcdefg")
    string input_5 = "abcdefg";
    cout << "Test Case 5: s = ";
    cout << input_5;
    cout << " -> Longest Palindrome: ";
    cout << solution.longestPalindrome(input_5) << endl;

    // Test Case 6: Long string with mixed palindromes (s = "racecarabcdeedcbaxyzzyx")
    string input_6 = "racecarabcdeedcbaxyzzyx";
    cout << "Test Case 6: s = ";
    cout << input_6;
    cout << " -> Longest Palindrome: ";
    cout << solution.longestPalindrome(input_6) << endl;

    return 0;
}
