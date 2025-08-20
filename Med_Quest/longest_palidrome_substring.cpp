// LeetCode Problem 5: Longest Palindromic Substring
// Difficulty: Medium
// Description: Given a string s, return the longest palindromic substring in s.
//              A palindrome is a string that reads the same forward and backward.
// Constraints:
//   - 1 <= s.length <= 1000
//   - s consists of only digits and lowercase English letters
// Algorithmic Pattern: Two Pointers
//   - The solution will likely use the expand-around-center approach, where two
//     pointers expand around each character or between characters to find the
//     longest palindrome. This achieves O(n²) time and O(1) space, making it
//     intuitive and suitable for debugging.

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        int string_length = s.length();
        if (string_length == 0) {
            return "";
        }

        // Variables to track the longest palindrome found
        int longest_palindrome_start = 0;
        int longest_palindrome_length = 1; // At least one character is a palindrome

        // Iterate through each character as a potential center
        for (int center_index = 0; center_index < string_length; center_index++) {
            // Check odd-length palindrome (center at current character)
            int left_pointer = center_index;
            int right_pointer = center_index;
            int current_length = 1; // Single character is a palindrome

            // Expand around center while within bounds and characters match
            while (left_pointer - 1 >= 0 && right_pointer + 1 < string_length &&
                   s[left_pointer - 1] == s[right_pointer + 1]) {
                left_pointer--;
                right_pointer++;
                current_length += 2;
                // Debug print (commented out)
                // cout << "Odd: center=" << center_index << ", left=" << left_pointer
                //      << ", right=" << right_pointer << ", len=" << current_length << endl;
            }

            // Update longest palindrome if current one is longer
            if (current_length > longest_palindrome_length) {
                longest_palindrome_start = left_pointer;
                longest_palindrome_length = current_length;
            }

            // Check even-length palindrome (center between current and next character)
            if (center_index + 1 < string_length && s[center_index] == s[center_index + 1]) {
                left_pointer = center_index;
                right_pointer = center_index + 1;
                current_length = 2; // Two adjacent characters

                // Expand while within bounds and characters match
                while (left_pointer - 1 >= 0 && right_pointer + 1 < string_length &&
                       s[left_pointer - 1] == s[right_pointer + 1]) {
                    left_pointer--;
                    right_pointer++;
                    current_length += 2;
                    // Debug print (commented out)
                    // cout << "Even: center=" << center_index << ", left=" << left_pointer
                    //      << ", right=" << right_pointer << ", len=" << current_length << endl;
                }

                // Update longest palindrome if current one is longer
                if (current_length > longest_palindrome_length) {
                    longest_palindrome_start = left_pointer;
                    longest_palindrome_length = current_length;
                }
            }
        }

        // Extract the substring using start index and length
        string longest_palindrome_substring = s.substr(longest_palindrome_start, longest_palindrome_length);
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
