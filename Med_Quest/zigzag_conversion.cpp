// LeetCode Problem 6: Zigzag Conversion
// Difficulty: Medium
// Description: The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
//              of rows like this: (you may want to display this pattern in a fixed font
//              for better legibility)
//
//              P   A   H   N
//              A P L S I I G
//              Y   I   R
//
//              And then read line by line: "PAHNAPLSIIGYIR"
//
//              Write the code that will take a string and make this conversion given a
//              number of rows:
//
//              string convert(string s, int numRows);
// Constraints:
//   - 1 <= s.length <= 1000
//   - s consists of English letters (lower-case and upper-case), ',' and '.'.
//   - 1 <= numRows <= 1000
// Algorithmic Pattern: Matrix Traversal
//   - The solution typically simulates the zigzag pattern by traversing the string
//     and placing characters into rows (e.g., vector of strings), then concatenating
//     the rows. This achieves O(n) time and O(n) space, where n = s.length().

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Helper function to print vector contents in [a, b, c] format (for test cases if needed)
void printVector(const vector<char>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

class Solution {
public:
    string convert(string s, int numRows) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/
        int string_length = s.length();
        if (numRows == 1 || numRows >= string_length) {
            return s; // No zigzag needed
        }

        // Initialize rows as vector of strings
        vector<string> zigzag_rows(numRows);
        int current_row = 0;
        bool going_down = true; // Direction flag

        // Traverse the string and append to rows
        for (int i = 0; i < string_length; i++) {
            char current_char = s[i];
            zigzag_rows[current_row] += current_char;

            // Update row and direction
            if (going_down) 
            {
                current_row++;
                if (current_row == numRows - 1) 
                {
                    going_down = false;
                }
            } else 
            {
                current_row--;
                if (current_row == 0) 
                {
                    going_down = true;
                }
            }
        }

        // Concatenate all rows into result
        string result_string;
        for (int row = 0; row < numRows; row++) {
            result_string += zigzag_rows[row];
        }

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
    cout << "Test Case 1: s = ";
    cout << input_1;
    cout << ", numRows = ";
    cout << num_rows_1;
    cout << " -> Converted: ";
    cout << solution.convert(input_1, num_rows_1) << endl;

    // Test Case 2: Example from problem (s = "PAYPALISHIRING", numRows = 4)
    string input_2 = "PAYPALISHIRING";
    int num_rows_2 = 4;
    cout << "Test Case 2: s = ";
    cout << input_2;
    cout << ", numRows = ";
    cout << num_rows_2;
    cout << " -> Converted: ";
    cout << solution.convert(input_2, num_rows_2) << endl;

    // Test Case 3: numRows = 1 (edge case, no zigzag)
    string input_3 = "ABCDEF";
    int num_rows_3 = 1;
    cout << "Test Case 3: s = ";
    cout << input_3;
    cout << ", numRows = ";
    cout << num_rows_3;
    cout << " -> Converted: ";
    cout << solution.convert(input_3, num_rows_3) << endl;

    // Test Case 4: numRows > s.length() (all characters in separate rows)
    string input_4 = "AB";
    int num_rows_4 = 3;
    cout << "Test Case 4: s = ";
    cout << input_4;
    cout << ", numRows = ";
    cout << num_rows_4;
    cout << " -> Converted: ";
    cout << solution.convert(input_4, num_rows_4) << endl;

    // Test Case 5: Long string with mixed characters
    string input_5 = "LEETCODEISHIRING";
    int num_rows_5 = 3;
    cout << "Test Case 5: s = ";
    cout << input_5;
    cout << ", numRows = ";
    cout << num_rows_5;
    cout << " -> Converted: ";
    cout << solution.convert(input_5, num_rows_5) << endl;

    // Test Case 6: String with punctuation (per constraints)
    string input_6 = "A,B.C,D";
    int num_rows_6 = 2;
    cout << "Test Case 6: s = ";
    cout << input_6;
    cout << ", numRows = ";
    cout << num_rows_6;
    cout << " -> Converted: ";
    cout << solution.convert(input_6, num_rows_6) << endl;

    return 0;
}