#include <iostream>
#include <iomanip>
#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes due to the minus sign
        if (x < 0) {
            return false;
        }
        int original = x;
        int reverse = 0;
        while (x > 0) {
            int digit = x % 10;
            // Check for overflow: handle both INT_MAX and the boundary case where reverse == INT_MAX/10
            // Only need to check positive overflow since we've already filtered negative numbers at start
            if (reverse >= INT_MAX / 10) {
                return false;
            }
            reverse = reverse * 10 + digit;
            x /= 10;
        }
        return original == reverse;
    }
};

struct TestCase {
    const char* name;
    int input;
    bool expected;
};

int main() {
    Solution sol;
    
    // Data-driven test cases: each input paired with its expected result
    // Uses INT_MAX and INT_MIN for boundary tests
    const TestCase tests[] = {
        { "0 (single digit)"     ,   0, true },
        { "121 (3-digit palindrome)" , 121, true },
        { "1221 (4-digit palindrome)" , 1221, true },
        { "12321 (5-digit palindrome)", 12321, true },
        { "9 (single digit)"     ,   9, true },
        { "INT_MIN boundary"     ,-2147483648, false },
        { "INT_MAX boundary"     ,  2147483647, false },
        { "10 (not palindrome)"      ,  10, false },
        { "-10 (negative not palindrome)", -10, false },
        { "99 (2-digit palindrome)"  ,  99, true },
        { "1001 (4-digit palindrome)", 1001, true },
        { "-121 (negative)"          ,-121, false },
        { "-101 (negative)"          ,-101, false },
    };
    
    const int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;
    
    std::cout << "=== LeetCode Problem 9: Palindrome Number (Cleaned Test Harness) ===\n";
    std::cout << "No string conversion used. Data-driven test cases with INT_MAX/INT_MIN boundaries.\n\n";

    for (const auto& tc : tests) {
        bool result = sol.isPalindrome(tc.input);
        bool test_passed = (result == tc.expected);

        std::cout << "Test: " << std::setw(26) << tc.name << ": isPalindrome(";
        // Print input directly without std::to_string
        std::cout << tc.input;
        std::cout << ") -> Expected: ";
        std::cout << (tc.expected ? "true" : "false");
        std::cout << "; Got: ";
        std::cout << (result ? "true" : "false");
        if (test_passed) { 
            std::cout << " [PASS]\n"; 
            passed++; 
        } else { 
            std::cout << " [FAIL]\n";
        }
    }

    std::cout << "\n=== Summary ===\n";
    std::cout << "Total tests:  " << num_tests << "\n";
    std::cout << "Passed:       " << passed << "\n";
    std::cout << (passed == num_tests ? "All tests PASSED!\n" : "Some tests FAILED.\n");

    return (passed == num_tests) ? 0 : 1;
}
