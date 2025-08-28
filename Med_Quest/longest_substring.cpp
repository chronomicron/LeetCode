// LeetCode: 3. Longest Substring Without Repeating Characters
// Description:
// Given a string s, find the length of the longest substring without repeating
// characters. A substring is a contiguous sequence of characters.
//
// Constraints:
// - 0 <= s.length <= 5 * 10^4
// - s consists of English letters, digits, symbols, and spaces
//
// Test Cases:
// 1. Input: s = "abcabcbb"
//    Output: 3 (Explanation: The answer is "abc", length 3)
// 2. Input: s = "bbbbb"
//    Output: 1 (Explanation: The answer is "b", length 1)
// 3. Input: s = "pwwkew"
//    Output: 3 (Explanation: The answer is "wke", length 3)
// 4. Input: s = "abcdeafghijk"
//    Output: 11 (Explanation: The answer is "bcdeafghijk", length 11)
// 5. Input: s = "pqrstrpuvwxy"
//    Output: 9 (Explanation: The answer is "strpuvwxy", length 9)
// 6. Input: s = "lmnopqrlmstuvwxyz"
//    Output: 12 (Explanation: The answer is "qrlmstuvwxyz", length 12)

#include <iostream>          // For input/output operations
#include <string>            // For std::string
#include <unordered_map>     // For std::unordered_map
#include <algorithm>         // For std::max

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Initialize variables
        int string_length = s.length();
        int left_pointer = 0;
        int max_length = 0;
        unordered_map<char, int> character_index_map;

        // Iterate through the string with right pointer
        for (int right_pointer = 0; right_pointer < string_length; right_pointer++) {
            // Get the current character
            char current_char = s[right_pointer];

            // Check if the character is in the map and within the current window
            unordered_map<char, int>::iterator map_iterator = character_index_map.find(current_char);
            bool is_char_in_window = map_iterator != character_index_map.end() && 
                                    map_iterator->second >= left_pointer;

            // If character is a duplicate in the current window, move left pointer
            if (is_char_in_window) {
                int last_seen_index = map_iterator->second;
                left_pointer = last_seen_index + 1;
            }

            // Update the hashmap with the current character's index
            character_index_map[current_char] = right_pointer;

            // Update max length
            int current_length = right_pointer - left_pointer + 1;
            max價_length = max(max_length, current_length);

            // Debug print
            // cout << "Right: " << right_pointer << ", Char: " << current_char
            //      << ", Left: " << left_pointer << ", Current Length: " << current_length
            //      << ", Max Length: " << max_length << endl;
        }

        return max_length;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }

};

int main() {
    // Create Solution object
    Solution solution;

    // Test case 1: s = "abcabcbb"
    string test1 = "abcabcbb";
    int result1 = solution.lengthOfLongestSubstring(test1);
    cout << "Input: s = \"" << test1 << "\", Output: " << result1 << endl;

    // Test case 2: s = "bbbbb"
    string test2 = "bbbbb";
    int result2 = solution.lengthOfLongestSubstring(test2);
    cout << "Input: s = \"" << test2 << "\", Output: " << result2 << endl;

    // Test case 3: s = "pwwkew"
    string test3 = "pwwkew";
    int result3 = solution.lengthOfLongestSubstring(test3);
    cout << "Input: s = \"" << test3 << "\", Output: " << result3 << endl;

    // Test case 4: s = "abcdeafghijk"
    string test4 = "abcdeafghijk";
    int result4 = solution.lengthOfLongestSubstring(test4);
    cout << "Input: s = \"" << test4 << "\", Output: " << result4 << endl;

    // Test case 5: s = "pqrstrpuvwxy"
    string test5 = "pqrstrpuvwxy";
    int result5 = solution.lengthOfLongestSubstring(test5);
    cout << "Input: s = \"" << test5 << "\", Output: " << result5 << endl;

    // Test case 6: s = "lmnopqrlmstuvwxyz"
    string test6 = "lmnopqrlmstuvwxyz";
    int result6 = solution.lengthOfLongestSubstring(test6);
    cout << "Input: s = \"" << test6 << "\", Output: " << result6 << endl;

    return 0;
}
