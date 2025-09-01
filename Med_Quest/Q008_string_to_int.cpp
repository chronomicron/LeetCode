// LeetCode Problem 8: String to Integer (atoi)
// Difficulty: Medium
// Description: Implement myAtoi(string s) to convert a string to a 32-bit signed integer.
//              Steps: 1) Skip leading whitespace; 2) Read optional sign (+/-); 
//              3) Read digits, ignoring leading zeros, until a non-digit or end;
//              4) If result exceeds [-2^31, 2^31 - 1], return INT_MIN or INT_MAX.
//              Return 0 if no valid digits are read.
// Constraints:
//   - 0 <= s.length <= 200
//   - s consists of English letters, digits, ' ', '+', '-', and '.'
//   - Assume no 64-bit integers allowed
// Algorithmic Pattern: Math
//   - Parse the string character by character, build the integer digit by digit,
//     and check for overflow. Achieves O(n) time (n = string length) and O(1) space.

#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Get the length of the input string
        int string_length = s.length();

        // Step 2: Initialize variables for parsing
        int current_index = 0;
        int result_number = 0;
        bool is_negative = false;

        // Step 3: Skip leading whitespace
        while (current_index < string_length && s[current_index] == ' ') {
            current_index++;
        }

        // Step 4: Check for sign after whitespace
        if (current_index < string_length) {
            if (s[current_index] == '-') {
                is_negative = true;
                current_index++;
            } else if (s[current_index] == '+') {
                current_index++;
            } else if (!isdigit(s[current_index])) {
                // If not a digit or sign, return 0
                return 0;
            }
        } else {
            // Empty string or only whitespace, return 0
            return 0;
        }

        // Step 5: Skip leading zeros after sign
        while (current_index < string_length && s[current_index] == '0') {
            current_index++;
        }

        // Step 6: Parse digits until non-digit or end of string
        while (current_index < string_length && isdigit(s[current_index])) {
            // Step 6.1: Get the current digit
            int current_digit = s[current_index] - '0';

            // Step 6.2: Check for potential overflow before adding digit
            if (result_number > INT_MAX / 10) {
                if (is_negative) {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            } else if (result_number == INT_MAX / 10) {
                if (current_digit > INT_MAX % 10) {
                    if (is_negative) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                }
            }

            // Step 6.3: Add the digit to the result
            result_number = result_number * 10 + current_digit;

            // Step 6.4: Move to the next character
            current_index++;

            // Debug print (commented out)
            // cout << "Index: " << current_index << ", Digit: " << current_digit
            //      << ", Result: " << result_number << endl;
        }

        // Step 7: Apply the sign to the result
        if (is_negative) {
            return -result_number;
        } else {
            return result_number;
        }

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (s = "42")
    string input_1 = "42";
    cout << "Test Case 1: s = " << input_1 << " -> Result: ";
    cout << solution.myAtoi(input_1) << endl;

    // Test Case 2: Example from problem (s = " -042")
    string input_2 = " -042";
    cout << "Test Case 2: s = " << input_2 << " -> Result: ";
    cout << solution.myAtoi(input_2) << endl;

    // Test Case 3: Example from problem (s = "1337c0d3")
    string input_3 = "1337c0d3";
    cout << "Test Case 3: s = " << input_3 << " -> Result: ";
    cout << solution.myAtoi(input_3) << endl;

    // Test Case 4: Example from problem (s = "0-1")
    string input_4 = "0-1";
    cout << "Test Case 4: s = " << input_4 << " -> Result: ";
    cout << solution.myAtoi(input_4) << endl;

    // Test Case 5: Example from problem (s = "words and 987")
    string input_5 = "words and 987";
    cout << "Test Case 5: s = " << input_5 << " -> Result: ";
    cout << solution.myAtoi(input_5) << endl;

    // Test Case 6: Empty string (s = "")
    string input_6 = "";
    cout << "Test Case 6: s = " << input_6 << " -> Result: ";
    cout << solution.myAtoi(input_6) << endl;

    // Test Case 7: Leading zeros with sign (s = "   +000123")
    string input_7 = "   +000123";
    cout << "Test Case 7: s = " << input_7 << " -> Result: ";
    cout << solution.myAtoi(input_7) << endl;

    return 0;
}
