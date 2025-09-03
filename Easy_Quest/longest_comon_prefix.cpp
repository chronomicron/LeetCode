// LeetCode Problem 14: Longest Common Prefix
// Difficulty: Easy
// Description: Given an array of strings strs, find the longest common prefix string
//              shared by all strings. Return an empty string "" if no common prefix exists.
// Constraints:
//   - 1 <= strs.length <= 200
//   - 0 <= strs[i].length <= 200
//   - strs[i] contains only lowercase English letters if non-empty
// Algorithmic Pattern: String Comparison
//   - Use the first string as a reference, compare characters position by position across
//     all strings, and stop at the first mismatch or end of a string. Achieves O(S) time
//     (S = total characters in all strings) and O(1) space (excluding output).

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Handle edge case: if the array is empty, return empty string
        if (strs.empty()) {
            return "";
        }

        // Step 2: Handle edge case: if any string is empty, return empty string
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].empty()) {
                return "";
            }
        }

        // Step 3: Use the first string as the reference for comparison
        string reference_string = strs[0];
        int prefix_length = reference_string.length();

        // Step 4: Iterate through characters of the reference string
        for (int char_index = 0; char_index < prefix_length; char_index++) {
            char current_char = reference_string[char_index];

            // Step 4.1: Compare the current character with the same position in all other strings
            for (int string_index = 1; string_index < strs.size(); string_index++) {
                // Step 4.1.1: Check if the current string is too short
                if (char_index >= strs[string_index].length()) {
                    // If we reach the end of any string, the prefix ends here
                    prefix_length = char_index;
                    return reference_string.substr(0, prefix_length);
                }

                // Step 4.1.2: Check if characters match
                if (strs[string_index][char_index] != current_char) {
                    // Mismatch found, the prefix ends here
                    prefix_length = char_index;
                    return reference_string.substr(0, prefix_length);
                }
            }

            // Debug print (commented out)
            // cout << "Char Index: " << char_index << ", Char: " << current_char
            //      << ", Prefix Length: " << prefix_length << endl;
        }

        // Step 5: If no mismatch is found, return the entire reference string up to prefix_length
        return reference_string.substr(0, prefix_length);

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (strs = ["flower","flow","flight"])
    vector<string> input_1 = {"flower", "flow", "flight"};
    cout << "Test Case 1: strs = [\"flower\",\"flow\",\"flight\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_1) << endl;

    // Test Case 2: Example from problem (strs = ["dog","racecar","car"])
    vector<string> input_2 = {"dog", "racecar", "car"};
    cout << "Test Case 2: strs = [\"dog\",\"racecar\",\"car\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_2) << endl;

    // Test Case 3: Single string (strs = ["hello"])
    vector<string> input_3 = {"hello"};
    cout << "Test Case 3: strs = [\"hello\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_3) << endl;

    // Test Case 4: Identical strings (strs = ["test","test","test"])
    vector<string> input_4 = {"test", "test", "test"};
    cout << "Test Case 4: strs = [\"test\",\"test\",\"test\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_4) << endl;

    // Test Case 5: Empty strings (strs = ["","abc","def"])
    vector<string> input_5 = {"", "abc", "def"};
    cout << "Test Case 5: strs = [\"\",\"abc\",\"def\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_5) << endl;

    // Test Case 6: Common prefix longer (strs = ["prefix","preface","preliminary"])
    vector<string> input_6 = {"prefix", "preface", "preliminary"};
    cout << "Test Case 6: strs = [\"prefix\",\"preface\",\"preliminary\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_6) << endl;

    // Test Case 7: One character prefix (strs = ["a","ab","abc"])
    vector<string> input_7 = {"a", "ab", "abc"};
    cout << "Test Case 7: strs = [\"a\",\"ab\",\"abc\"] -> Prefix: ";
    cout << solution.longestCommonPrefix(input_7) << endl;

    return 0;
}
