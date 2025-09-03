// LeetCode Problem 12: Integer to Roman
// Difficulty: Medium
// Description: Convert a given integer (1 <= num <= 3999) to a Roman numeral string
//              using symbols I, V, X, L, C, D, M and subtractive forms IV, IX, XL, XC,
//              CD, CM. Process from highest to lowest value, using the largest possible
//              symbol or subtractive pair each time.
// Constraints:
//   - 1 <= num <= 3999
// Algorithmic Pattern: Greedy/Math
//   - Use a predefined array of value-symbol pairs, subtract the largest possible value,
//     and append the corresponding symbol until the number is 0. Achieves O(1) time
//     (fixed number of Roman numeral symbols) and O(1) space (bounded output size).

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Define the array of value-symbol pairs in descending order
        //         Includes standard values (1000, 500, 100, etc.) and subtractive forms (900, 400, etc.)
        vector<pair<int, string>> value_symbol_pairs = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        // Step 2: Initialize the result string
        string result_roman = "";

        // Step 3: Initialize the remaining number to convert
        int remaining_number = num;

        // Step 4: Iterate through each value-symbol pair
        for (int pair_index = 0; pair_index < value_symbol_pairs.size(); pair_index++) {
            // Step 4.1: Get the current value and symbol
            int current_value = value_symbol_pairs[pair_index].first;
            string current_symbol = value_symbol_pairs[pair_index].second;

            // Step 4.2: While the remaining number is at least the current value
            while (remaining_number >= current_value) {
                // Step 4.2.1: Append the current symbol to the result
                result_roman += current_symbol;

                // Step 4.2.2: Subtract the current value from the remaining number
                remaining_number -= current_value;

                // Debug print (commented out)
                // cout << "Value: " << current_value << ", Symbol: " << current_symbol
                //      << ", Remaining: " << remaining_number << ", Result: " << result_roman << endl;
            }
        }

        // Step 5: Return the final Roman numeral string
        return result_roman;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (num = 3749)
    int input_1 = 3749;
    cout << "Test Case 1: num = " << input_1 << " -> Roman: ";
    cout << solution.intToRoman(input_1) << endl;

    // Test Case 2: Example from problem (num = 58)
    int input_2 = 58;
    cout << "Test Case 2: num = " << input_2 << " -> Roman: ";
    cout << solution.intToRoman(input_2) << endl;

    // Test Case 3: Example from problem (num = 1994)
    int input_3 = 1994;
    cout << "Test Case 3: num = " << input_3 << " -> Roman: ";
    cout << solution.intToRoman(input_3) << endl;

    // Test Case 4: Minimum value (num = 1)
    int input_4 = 1;
    cout << "Test Case 4: num = " << input_4 << " -> Roman: ";
    cout << solution.intToRoman(input_4) << endl;

    // Test Case 5: Maximum value (num = 3999)
    int input_5 = 3999;
    cout << "Test Case 5: num = " << input_5 << " -> Roman: ";
    cout << solution.intToRoman(input_5) << endl;

    // Test Case 6: Simple subtractive form (num = 4)
    int input_6 = 4;
    cout << "Test Case 6: num = " << input_6 << " -> Roman: ";
    cout << solution.intToRoman(input_6) << endl;

    // Test Case 7: Multiple subtractive forms (num = 944)
    int input_7 = 944;
    cout << "Test Case 7: num = " << input_7 << " -> Roman: ";
    cout << solution.intToRoman(input_7) << endl;

    return 0;
}
