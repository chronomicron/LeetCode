/*
 * LeetCode 217: Contains Duplicate
 * https://leetcode.com/problems/contains-duplicate/
 *
 * Return true if any integer occurs more than once in the input vector;
 * otherwise return false.
 *
 * This standalone C++ scaffold includes local tests. Implement
 * containsDuplicate between the markers. Consider how a set can record values
 * already seen while scanning the vector.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums)
    {
        /* BEGIN YOUR CODE HERE */
        std::unordered_set<int> seen;
        bool has_duplicate = false;

        for (int num = 0; num < nums.size(); num++) {
            if (seen.find(nums[num]) != seen.end()) {
                has_duplicate = true;
                break;
            }
            seen.insert(nums[num]);
        }

        return has_duplicate;

        /* END YOUR CODE HERE */
    }
};

static bool run_test(const std::string& name,
                     const std::vector<int>& nums,
                     bool expected)
{
    Solution solution;
    const bool result = solution.containsDuplicate(nums);
    const bool pass = result == expected;

    std::cout << name << ": " << (pass ? "PASS" : "FAIL")
              << " (got " << std::boolalpha << result
              << ", expected " << expected << ")\n";
    return pass;
}

int main()
{
    int passed = 0;
    int total = 0;

    passed += run_test("LeetCode example 1", {1, 2, 3, 1}, true);
    ++total;
    passed += run_test("LeetCode example 2", {1, 2, 3, 4}, false);
    ++total;
    passed += run_test("LeetCode example 3", {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true);
    ++total;
    passed += run_test("Negative values", {-5, 0, -5}, true);
    ++total;
    passed += run_test("Empty vector (extra edge case)", {}, false);
    ++total;

    std::cout << "\n" << passed << "/" << total << " tests passed.\n";
    return passed == total ? 0 : 1;
}
