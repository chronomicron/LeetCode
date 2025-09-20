// LeetCode Problem 17: Letter Combinations of a Phone Number
// Difficulty: Medium
// Description: Given a string digits (2-9), return all possible letter combinations
//              based on the telephone keypad mapping. Return in any order.
// Constraints:
//   - 0 <= digits.length <= 4
//   - digits[i] is a digit from '2' to '9'
// Algorithmic Pattern: Backtracking
//   - Use recursion to build combinations by selecting one letter per digit.
//     Achieves O(3^N * 4^M) time (N = digits with 3 letters, M = digits with 4 letters)
//     and O(N) space for recursion stack (excluding output).

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Handle edge case: if digits is empty, return empty vector
        if (digits.empty()) {
            return {};
        }

        // Step 2: Define the digit-to-letters mapping
        unordered_map<char, string> digit_to_letters;
        digit_to_letters['2'] = "abc";
        digit_to_letters['3'] = "def";
        digit_to_letters['4'] = "ghi";
        digit_to_letters['5'] = "jkl";
        digit_to_letters['6'] = "mno";
        digit_to_letters['7'] = "pqrs";
        digit_to_letters['8'] = "tuv";
        digit_to_letters['9'] = "wxyz";

        // Step 3: Initialize result vector to store combinations
        vector<string> result_combinations;

        // Step 4: Initialize current combination string for backtracking
        string current_combination = "";

        // Step 5: Call backtracking function to generate combinations
        backtrack(digits, 0, current_combination, digit_to_letters, result_combinations);

        // Step 6: Return the list of all combinations
        return result_combinations;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }

private:
    // Helper function for backtracking
    void backtrack(const string& digits, int current_index, string& current_combination,
                   const unordered_map<char, string>& digit_to_letters,
                   vector<string>& result_combinations) {
        // Step A: Base case: if current combination length equals digits length, add to result
        if (current_combination.length() == digits.length()) {
            result_combinations.push_back(current_combination);
            return;
        }

        // Step B: Get the letters for the current digit
        char current_digit = digits[current_index];
        string letters = digit_to_letters.at(current_digit);

        // Step C: Iterate through each letter for the current digit
        for (int letter_index = 0; letter_index < letters.length(); letter_index++) {
            // Step C.1: Append the current letter to the combination
            current_combination.push_back(letters[letter_index]);

            // Step C.2: Recurse for the next digit
            backtrack(digits, current_index + 1, current_combination, digit_to_letters, result_combinations);

            // Step C.3: Backtrack by removing the last letter
            current_combination.pop_back();

            // Debug print (commented out)
            // cout << "Index: " << current_index << ", Letter: " << letters[letter_index]
            //      << ", Current: " << current_combination << endl;
        }
    }
};

// Helper function to print vector of strings for test output
void printResult(const vector<string>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

int main() {
    Solution solution;

    // Test Case 1: Example from problem (digits = "23")
    string input_1 = "23";
    cout << "Test Case 1: digits = \"" << input_1 << "\" -> Combinations: ";
    printResult(solution.letterCombinations(input_1));
    cout << endl;

    // Test Case 2: Example from problem (digits = "")
    string input_2 = "";
    cout << "Test Case 2: digits = \"" << input_2 << "\" -> Combinations: ";
    printResult(solution.letterCombinations(input_2));
    cout << endl;

    // Test Case 3: Example from problem (digits = "2")
    string input_3 = "2";
    cout << "Test Case 3: digits = \"" << input_3 << "\" -> Combinations: ";
    printResult(solution.letterCombinations(input_3));
    cout << endl;

    // Test Case 4: Maximum length (digits = "2345")
    string input_4 = "2345";
    cout << "Test Case 4: digits = \"" << input_4 << "\" -> Combinations: ";
    printResult(solution.letterCombinations(input_4));
    cout << endl;

    // Test Case 5: Single digit with 4 letters (digits = "7")
    string input_5 = "7";
    cout << "Test Case 5: digits = \"" << input_5 << "\" -> Combinations: ";
    printResult(solution.letterCombinations(input_5));
    cout << endl;

    // Test Case 6: Repeated digits (digits = "22")
    string input_6 = "22";
    cout << "Test Case 6: digits = \"" << input_6 << "\" -> Combinations: ";
    printResult(solution.letterCombinations(input_6));
    cout << endl;

    return 0;
}
