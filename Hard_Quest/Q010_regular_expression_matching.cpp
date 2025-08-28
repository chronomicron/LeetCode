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

        return true;

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
    cout << (solution.isMatch(input_s_1, input_p_1) ? "true" : "false") << endl;

    // Test Case 2: Example from problem (s = "aa", p = "a*")
    string input_s_2 = "aa";
    string input_p_2 = "a*";
    cout << "Test Case 2: s = \"" << input_s_2 << "\", p = \"" << input_p_2
         << "\" -> Is Match: ";
    cout << (solution.isMatch(input_s_2, input_p_2) ? "true" : "false") << endl;

    // Test Case 3: Example from problem (s = "ab", p = ".*")
    string input_s_3 = "ab";
    string input_p_3 = ".*";
    cout << "Test Case 3: s = \"" << input_s_3 << "\", p = \"" << input_p_3
         << "\" -> Is Match: ";
    cout << (solution.isMatch(input_s_3, input_p_3) ? "true" : "false") << endl;

    // Test Case 4: Complex * usage (s = "aab", p = "c*a*b")
    string input_s_4 = "aab";
    string input_p_4 = "c*a*b";
    cout << "Test Case 4: s = \"" << input_s_4 << "\", p = \"" << input_p_4
         << "\" -> Is Match: ";
    cout << (solution.isMatch(input_s_4, input_p_4) ? "true" : "false") << endl;

    // Test Case 5: Non-matching pattern (s = "mississippi", p = "mis*is*p*.")
    string input_s_5 = "mississippi";
    string input_p_5 = "mis*is*p*.";
    cout << "Test Case 5: s = \"" << input_s_5 << "\", p = \"" << input_p_5
         << "\" -> Is Match: ";
    cout << (solution.isMatch(input_s_5, input_p_5) ? "true" : "false") << endl;

    // Test Case 6: Overlapping * (s = "aaa", p = "a*a")
    string input_s_6 = "aaa";
    string input_p_6 = "a*a";
    cout << "Test Case 6: s = \"" << input_s_6 << "\", p = \"" << input_p_6
         << "\" -> Is Match: ";
    cout << (solution.isMatch(input_s_6, input_p_6) ? "true" : "false") << endl;

    // Test Case 7: Partial match (s = "abcd", p = "d*")
    string input_s_7 = "abcd";
    string input_p_7 = "d*";
    cout << "Test Case 7: s = \"" << input_s_7 << "\", p = \"" << input_p_7
         << "\" -> Is Match: ";
    cout << (solution.isMatch(input_s_7, input_p_7) ? "true" : "false") << endl;

    return 0;
}
