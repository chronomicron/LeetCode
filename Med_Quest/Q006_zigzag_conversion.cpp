// LeetCode Problem 6: Zigzag Conversion
// Difficulty: Medium
// Description: Convert a string s to a zigzag pattern on numRows rows, then read it line by line.
// Constraints:
//   - 1 <= s.length <= 1000
//   - 1 <= numRows <= 1000
//   - s consists of English letters (lower-case and upper-case), ',' and '.'.
// Algorithmic Pattern: Two Pointers
//   - Simulate the zigzag by moving a pointer up and down rows, appending characters to row-specific strings,
//     and flipping direction at boundaries. This achieves O(s.length()) time and O(s.length()) space.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Get the length of the input string
        int string_length = s.length();

        // Step 2: Handle special case where numRows is 1 or numRows is greater than or equal to string length
        //         In these cases, no zigzag is needed, return the original string
        if (numRows == 1 || numRows >= string_length) {
            return s;
        }

        // Step 3: Initialize a vector of strings, one for each row
        vector<string> row_strings(numRows, "");

        // Step 4: Initialize variables for the current row and direction
        int current_row = 0;
        bool direction_down = true; // Start by going down

        // Step 5: Iterate through each character in the string
        for (int char_index = 0; char_index < string_length; char_index++) {
            // Step 5.1: Get the current character
            char current_char = s[char_index];

            // Step 5.2: Append the current character to the current row's string
            row_strings[current_row] += current_char;

            // Step 5.3: Update the current row based on the direction
            if (direction_down) {
                current_row++;
            } else {
                current_row--;
            }

            // Step 5.4: Flip the direction if we reach the top or bottom row
            if (current_row == numRows - 1) {
                direction_down = false; // Reached bottom, now go up
            } else if (current_row == 0) {
                direction_down = true; // Reached top, now go down
            }

            // Debug print (commented out)
            // cout << "Char: " << current_char << ", Row: " << current_row << ", Dir Down: " << direction_down << endl;
        }

        // Step 6: Concatenate all row strings to form the result
        string result_string = "";
        for (int row_index = 0; row_index < numRows; row_index++) {
            result_string += row_strings[row_index];
        }

        // Step 7: Return the result string
        return result_string;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (s = "PAYPALISHIRING", numRows = 3)
    string input_1 = "PAYPALISHIRING";
    int num_rows_1 = 3;
    cout << "Test Case 1: s = " << input_1 << ", numRows = " << num_rows_1 << " -> Result: ";
    cout << solution.convert(input_1, num_rows_1) << endl;

    // Test Case 2: Example from problem (s = "PAYPALISHIRING", numRows = 4)
    string input_2 = "PAYPALISHIRING";
    int num_rows_2 = 4;
    cout << "Test Case 2: s = " << input_2 << ", numRows = " << num_rows_2 << " -> Result: ";
    cout << solution.convert(input_2, num_rows_2) << endl;

    // Test Case 3: Short string (s = "AB", numRows = 1)
    string input_3 = "AB";
    int num_rows_3 = 1;
    cout << "Test Case 3: s = " << input_3 << ", numRows = " << num_rows_3 << " -> Result: ";
    cout << solution.convert(input_3, num_rows_3) << endl;

    // Test Case 4: numRows > length (s = "A", numRows = 2)
    string input_4 = "A";
    int num_rows_4 = 2;
    cout << "Test Case 4: s = " << input_4 << ", numRows = " << num_rows_4 << " -> Result: ";
    cout << solution.convert(input_4, num_rows_4) << endl;

    // Test Case 5: Long string with punctuation (s = "HELLO,WORLD!", numRows = 2)
    string input_5 = "HELLO,WORLD!";
    int num_rows_5 = 2;
    cout << "Test Case 5: s = " << input_5 << ", numRows = " << num_rows_5 << " -> Result: ";
    cout << solution.convert(input_5, num_rows_5) << endl;

    // Test Case 6: Mixed case long string (s = "LeetCodeZigZagExampleWithMoreCharactersToTest", numRows = 5)
    string input_6 = "LeetCodeZigZagExampleWithMoreCharactersToTest";
    int num_rows_6 = 5;
    cout << "Test Case 6: s = " << input_6 << ", numRows = " << num_rows_6 << " -> Result: ";
    cout << solution.convert(input_6, num_rows_6) << endl;

    return 0;
}