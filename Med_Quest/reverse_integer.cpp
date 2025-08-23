// LeetCode Problem 7: Reverse Integer
// Difficulty: Medium
// Description: Given a signed 32-bit integer x, return x with its digits reversed.
//              If reversing x causes the value to go outside the signed 32-bit
//              integer range [-2^31, 2^31 - 1], return 0. Assume the environment
//              does not allow storing 64-bit integers (signed or unsigned).
// Constraints:
//   - -2^31 <= x <= 2^31 - 1
// Algorithmic Pattern: Math
//   - The solution typically extracts digits using modulo and division, builds the
//     reversed integer, and checks for overflow against the 32-bit signed integer
//     range. Achieves O(log x) time (number of digits) and O(1) space.

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (x = 123)
    int input_1 = 123;
    cout << "Test Case 1: x = " << input_1 << " -> Reversed: ";
    cout << solution.reverse(input_1) << endl;

    // Test Case 2: Example from problem (x = -123)
    int input_2 = -123;
    cout << "Test Case 2: x = " << input_2 << " -> Reversed: ";
    cout << solution.reverse(input_2) << endl;

    // Test Case 3: Example from problem (x = 120)
    int input_3 = 120;
    cout << "Test Case 3: x = " << input_3 << " -> Reversed: ";
    cout << solution.reverse(input_3) << endl;

    // Test Case 4: Zero (x = 0)
    int input_4 = 0;
    cout << "Test Case 4: x = " << input_4 << " -> Reversed: ";
    cout << solution.reverse(input_4) << endl;

    // Test Case 5: Max 32-bit integer (x = 2147483647)
    int input_5 = 2147483647;
    cout << "Test Case 5: x = " << input_5 << " -> Reversed: ";
    cout << solution.reverse(input_5) << endl;

    // Test Case 6: Min 32-bit integer (x = -2147483648)
    int input_6 = -2147483648;
    cout << "Test Case 6: x = " << input_6 << " -> Reversed: ";
    cout << solution.reverse(input_6) << endl;

    // Test Case 7: Large number causing overflow (x = 1000000009)
    int input_7 = 1000000009;
    cout << "Test Case 7: x = " << input_7 << " -> Reversed: ";
    cout << solution.reverse(input_7) << endl;

    return 0;
}