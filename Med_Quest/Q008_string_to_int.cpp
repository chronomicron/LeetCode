// LeetCode Problem 8: String to Integer (atoi)
// Difficulty: Medium
// Description: Implement myAtoi(string s) to convert a string to a 32-bit signed integer.
//              Steps: 1) Skip leading whitespace; 2) Read optional sign (+/-);
//              3) If next character is not a digit or sign, return 0;
//              4) Read digits, ignoring leading zeros, until a non-digit or end;
//              5) If result exceeds [-2^31, 2^31 - 1], return INT_MIN or INT_MAX.
//              Return 0 if no valid digits are read.
// Constraints:
//   - 0 <= s.length <= 200
//   - s consists of English letters, digits, ' ', '+', '-', and '.'
//   - Assume no 64-bit integers allowed
// Algorithmic Pattern: Math
//   - Parse the string character by character, build the integer digit by digit,
//     and check for overflow. Stops at first non-digit/sign after whitespace.
//     Achieves O(n) time (n = string length) and O(1) space.

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

        // Initialize variables
        int string_length = s.length();
        int current_index = 0;
        int result_number = 0;
        bool is_negative = false;

        // Debug: Log entry
        // cout << "Entering myAtoi with s = \"" << s << "\"" << endl;

        // Step 1: Skip leading whitespace
        while (current_index < string_length && s[current_index] == ' ') {
            current_index++;
        }

        // Step 2: Check for sign or invalid character
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
            // Empty string or only whitespace
            return 0;
        }

        // Step 3: Skip leading zeros
        while (current_index < string_length && s[current_index] == '0') {
            current_index++;
        }

        // Step 4: Parse digits
        while (current_index < string_length && isdigit(s[current_index])) {
            int current_digit = s[current_index] - '0';

            // Check for overflow
            if (result_number > INT_MAX / 10 || 
                (result_number == INT_MAX / 10 && current_digit > INT_MAX % 10)) {
                return is_negative ? INT_MIN : INT_MAX;
            }

            // Build result
            result_number = result_number * 10 + current_digit;
            current_index++;

            // Debug print
            // cout << "Index: " << current_index << ", Digit: " << current_digit
            //      << ", Result: " << result_number << endl;
        }

        // Step 5: Apply sign
        return is_negative ? -result_number : result_number;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (s = "42")
    string input_1 = "42";
    cout << "Test Case 1: s = \"" << input_1 << "\" -> Result: ";
    cout << solution.myAtoi(input_1) << endl;

    // Test Case 2: Example from problem (s = " -042")
    string input_2 = " -042";
    cout << "Test Case 2: s = \"" << input_2 << "\" -> Result: ";
    cout << solution.myAtoi(input_2) << endl;

    // Test Case 3: Example from problem (s = "1337c0d3")
    string input_3 = "1337c0d3";
    cout << "Test Case 3: s = \"" << input_3 << "\" -> Result: ";
    cout << solution.myAtoi(input_3) << endl;

    // Test Case 4: Example from problem (s = "0-1")
    string input_4 = "0-1";
    cout << "Test Case 4: s = \"" << input_4 << "\" -> Result: ";
    cout << solution.myAtoi(input_4) << endl;

    // Test Case 5: Example from problem (s = "words and 987")
    string input_5 = "words and 987";
    cout << "Test Case 5: s = \"" << input_5 << "\" -> Result: ";
    cout << solution.myAtoi(input_5) << endl;

    // Test Case 6: Empty string (s = "")
    string input_6 = "";
    cout << "Test Case 6: s = \"" << input_6 << "\" -> Result: ";
    cout << solution.myAtoi(input_6) << endl;

    // Test Case 7: Leading zeros with sign (s = "   +000123")
    string input_7 = "   +000123";
    cout << "Test Case 7: s = \"" << input_7 << "\" -> Result: ";
    cout << solution.myAtoi(input_7) << endl;

    return 0;
}