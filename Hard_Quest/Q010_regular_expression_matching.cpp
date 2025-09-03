// LeetCode Problem 10: Regular Expression Matching
// Difficulty: Hard
// Description: Given an input string s and a pattern p, implement regular expression
//              matching where '.' matches any single character and '*' matches zero
//              or more of the preceding element. The match must cover the entire string s.
// Constraints:
//   - 1 <= s.length <= 20
//   - 1 <= p.length <= 20
//   - s contains only lowercase English letters
//   - p contains lowercase English letters, '.', and '*'
//   - '*' is always preceded by a valid character
// Algorithmic Pattern: Dynamic Programming
//   - Use a 2D DP table where dp[i][j] indicates if s[0:i] matches p[0:j].
//     Handle '.' by matching any character and '*' by considering zero or more
//     occurrences. Achieves O(m*n) time (m = s.length, n = p.length) and O(m*n) space.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Get the lengths of the string and pattern
        int string_length = s.length();
        int pattern_length = p.length();

        // Step 2: Create a DP table of size (string_length + 1) x (pattern_length + 1)
        //         dp[i][j] will be true if the first i characters of s match the first j characters of p
        vector<vector<bool>> dp_table(string_length + 1, vector<bool>(pattern_length + 1, false));

        // Step 3: Initialize the DP table for base cases
        //         Empty string matches empty pattern
        dp_table[0][0] = true;

        // Step 4: Fill the first row of the DP table (empty string vs pattern)
        for (int j = 2; j <= pattern_length; j++) {
            if (p[j-1] == '*') {
                // If the pattern ends with '*', check if the previous pattern matches empty
                dp_table[0][j] = dp_table[0][j-2];
            } else {
                dp_table[0][j] = false;
            }
        }

        // Step 5: Fill the DP table for all combinations of i and j
        for (int i = 1; i <= string_length; i++) {
            for (int j = 1; j <= pattern_length; j++) {
                // Step 5.1: Get the current characters
                char current_s = s[i-1];
                char current_p = p[j-1];

                // Step 5.2: If the pattern character is '.' or matches the string character
                if (current_p == '.' || current_p == current_s) {
                    // Inherit the match from the previous characters
                    dp_table[i][j] = dp_table[i-1][j-1];
                } else if (current_p == '*') {
                    // Step 5.3: Handle '*' which can match zero or more of the preceding element
                    //           Check zero occurrences
                    dp_table[i][j] = dp_table[i][j-2];

                    // Step 5.4: Check one or more occurrences if the preceding matches
                    if (p[j-2] == '.' || p[j-2] == current_s) {
                        if (dp_table[i-1][j]) {
                            dp_table[i][j] = true;
                        }
                    }
                } else {
                    // No match
                    dp_table[i][j] = false;
                }

                // Debug print (commented out)
                // cout << "s[0:" << i << "]=\"" << s.substr(0, i) << "\", p[0:" << j
                //      << "]=\"" << p.substr(0, j) << "\", dp[" << i << "][" << j
                //      << "]=" << (dp_table[i][j] ? "true" : "false") << endl;
            }
        }

        // Step 6: The result is in the bottom-right corner of the DP table
        return dp_table[string_length][pattern_length];

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (s = "aa", p = "a")
    string input_s_1 = "aa";
    string input_p_1 = "a";
    cout << "Test Case 1: s = \"" << input_s_1 << "\", p = \"" << input_p_1
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_1, input_p_1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test Case 2: Example from problem (s = "aa", p = "a*")
    string input_s_2 = "aa";
    string input_p_2 = "a*";
    cout << "Test Case 2: s = \"" << input_s_2 << "\", p = \"" << input_p_2
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_2, input_p_2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test Case 3: Example from problem (s = "ab", p = ".*")
    string input_s_3 = "ab";
    string input_p_3 = ".*";
    cout << "Test Case 3: s = \"" << input_s_3 << "\", p = \"" << input_p_3
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_3, input_p_3)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test Case 4: Complex * usage (s = "aab", p = "c*a*b")
    string input_s_4 = "aab";
    string input_p_4 = "c*a*b";
    cout << "Test Case 4: s = \"" << input_s_4 << "\", p = \"" << input_p_4
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_4, input_p_4)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test Case 5: Non-matching pattern (s = "mississippi", p = "mis*is*p*.")
    string input_s_5 = "mississippi";
    string input_p_5 = "mis*is*p*.";
    cout << "Test Case 5: s = \"" << input_s_5 << "\", p = \"" << input_p_5
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_5, input_p_5)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test Case 6: Overlapping * (s = "aaa", p = "a*a")
    string input_s_6 = "aaa";
    string input_p_6 = "a*a";
    cout << "Test Case 6: s = \"" << input_s_6 << "\", p = \"" << input_p_6
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_6, input_p_6)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Test Case 7: Partial match (s = "abcd", p = "d*")
    string input_s_7 = "abcd";
    string input_p_7 = "d*";
    cout << "Test Case 7: s = \"" << input_s_7 << "\", p = \"" << input_p_7
         << "\" -> Is Match: ";
    if (solution.isMatch(input_s_7, input_p_7)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
