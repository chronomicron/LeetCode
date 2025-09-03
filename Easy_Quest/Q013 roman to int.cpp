// LeetCode Problem 13: Roman to Integer
// Difficulty: Easy
// Description: Given a Roman numeral string s (valid from 1 to 3999), convert it to an integer.
//              Roman numerals use symbols I(1), V(5), X(10), L(50), C(100), D(500), M(1000),
//              with subtractive forms IV(4), IX(9), XL(40), XC(90), CD(400), CM(900).
// Constraints:
//   - 1 <= s.length <= 15
//   - s contains only 'I', 'V', 'X', 'L', 'C', 'D', 'M'
//   - s is a valid Roman numeral in [1, 3999]
// Algorithmic Pattern: Math
//   - Iterate through the string, add the value if current >= next, else subtract.
//     Achieves O(n) time (n = s.length <= 15) and O(1) space.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Create a map for Roman symbols and their values
        unordered_map<char, int> roman_value_map;
        roman_value_map['I'] = 1;
        roman_value_map['V'] = 5;
        roman_value_map['X'] = 10;
        roman_value_map['L'] = 50;
        roman_value_map['C'] = 100;
        roman_value_map['D'] = 500;
        roman_value_map['M'] = 1000;

        // Step 2: Get the length of the input string
        int string_length = s.length();

        // Step 3: Initialize the result integer to 0
        int result_integer = 0;

        // Step 4: Iterate through the string from left to right
        for (int current_index = 0; current_index < string_length; current_index++) {
            // Step 4.1: Get the value of the current symbol
            int current_value = roman_value_map[s[current_index]];

            // Step 4.2: Check if there is a next symbol
            if (current_index + 1 < string_length) {
                // Step 4.2.1: Get the value of the next symbol
                int next_value = roman_value_map[s[current_index + 1]];

                // Step 4.2.2: If current value is less than next, subtract current value
                if (current_value < next_value) {
                    result_integer -= current_value;
                } else {
                    // Step 4.2.3: Else, add current value
                    result_integer += current_value;
                }
            } else {
                // Step 4.3: If no next symbol (last character), add current value
                result_integer += current_value;
            }

            // Debug print (commented out)
            // cout << "Index: " << current_index << ", Char: " << s[current_index]
            //      << ", Value: " << current_value << ", Result: " << result_integer << endl;
        }

        // Step 5: Return the final result
        return result_integer;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (s = "III")
    string input_1 = "III";
    cout << "Test Case 1: s = \"" << input_1 << "\" -> Integer: ";
    cout << solution.romanToInt(input_1) << endl;

    // Test Case 2: Example from problem (s = "LVIII")
    string input_2 = "LVIII";
    cout << "Test Case 2: s = \"" << input_2 << "\" -> Integer: ";
    cout << solution.romanToInt(input_2) << endl;

    // Test Case 3: Example from problem (s = "MCMXCIV")
    string input_3 = "MCMXCIV";
    cout << "Test Case 3: s = \"" << input_3 << "\" -> Integer: ";
    cout << solution.romanToInt(input_3) << endl;

    // Test Case 4: Minimum value (s = "I")
    string input_4 = "I";
    cout << "Test Case 4: s = \"" << input_4 << "\" -> Integer: ";
    cout << solution.romanToInt(input_4) << endl;

    // Test Case 5: Maximum value (s = "MMMCMXCIX")
    string input_5 = "MMMCMXCIX";
    cout << "Test Case 5: s = \"" << input_5 << "\" -> Integer: ";
    cout << solution.romanToInt(input_5) << endl;

    // Test Case 6: Subtractive form (s = "IX")
    string input_6 = "IX";
    cout << "Test Case 6: s = \"" << input_6 << "\" -> Integer: ";
    cout << solution.romanToInt(input_6) << endl;

    // Test Case 7: Mixed forms (s = "DCXXI")
    string input_7 = "DCXXI";
    cout << "Test Case 7: s = \"" << input_7 << "\" -> Integer: ";
    cout << solution.romanToInt(input_7) << endl;

    return 0;
}
