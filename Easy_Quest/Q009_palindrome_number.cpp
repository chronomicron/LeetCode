// LeetCode Problem 9: Palindrome Number
// Difficulty: Easy
// Description: Given a signed 32-bit integer x, return true if x is a palindrome
//              (reads the same forward and backward), false otherwise.
//              Negative numbers are not palindromes. Solve without converting to a string.
// Constraints:
//   - -2^31 <= x <= 2^31 - 1
//   - Assume no 64-bit integers allowed
// Algorithmic Pattern: Math
//   - Reverse the number using modulo and division, checking for overflow,
//     and compare with the original number. Achieves O(log x) time (number of digits)
//     and O(1) space.

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Handle negative numbers (not palindromes)
        if (x < 0) {
            return false;
        }

        // Handle zero
        if (x == 0) {
            return true;
        }

        // Initialize variables for reversal
        int original_number = x;
        int reversed_number = 0;
        int remaining_number = x;

        // Reverse the number
        while (remaining_number > 0) {
            // Extract the last digit
            int current_digit = remaining_number % 10;
            remaining_number /= 10;

            // Check for overflow before adding digit
            if (reversed_number > INT_MAX / 10 || 
                (reversed_number == INT_MAX / 10 && current_digit > INT_MAX % 10)) {
                return false; // Overflow, not a valid palindrome
            }

            // Build reversed number
            reversed_number = reversed_number * 10 + current_digit;

            // Debug print
            // cout << "Digit: " << current_digit << ", Reversed: " << reversed_number
            //      << ", Remaining: " << remaining_number << endl;
        }

        // Check if the number is a palindrome
        return reversed_number == original_number;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (x = 121)
    int input_1 = 121;
    cout << "Test Case 1: x = " << input_1 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_1) ? "true" : "false") << endl;

    // Test Case 2: Example from problem (x = -121)
    int input_2 = -121;
    cout << "Test Case 2: x = " << input_2 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_2) ? "true" : "false") << endl;

    // Test Case 3: Example from problem (x = 10)
    int input_3 = 10;
    cout << "Test Case 3: x = " << input_3 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_3) ? "true" : "false") << endl;

    // Test Case 4: Zero (x = 0)
    int input_4 = 0;
    cout << "Test Case 4: x = " << input_4 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_4) ? "true" : "false") << endl;

    // Test Case 5: Single digit (x = 5)
    int input_5 = 5;
    cout << "Test Case 5: x = " << input_5 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_5) ? "true" : "false") << endl;

    // Test Case 6: Large palindrome (x = 2147447412)
    int input_6 = 2147447412;
    cout << "Test Case 6: x = " << input_6 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_6) ? "true" : "false") << endl;

    // Test Case 7: Max 32-bit integer (x = 2147483647)
    int input_7 = 2147483647;
    cout << "Test Case 7: x = " << input_7 << " -> Is Palindrome: ";
    cout << (solution.isPalindrome(input_7) ? "true" : "false") << endl;

    return 0;
}