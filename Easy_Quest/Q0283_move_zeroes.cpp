/*
 * LeetCode 283: Move Zeroes
 * https://leetcode.com/problems/move-zeroes/
 *
 * Move every zero to the end of the vector while preserving the relative
 * order of the non-zero values. Modify the vector in place without making
 * another array.
 *
 * This standalone C++ scaffold includes local tests. Implement moveZeroes
 * between the markers; main() checks the complete vector afterward.
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>  // declares std::swap

class Solution {
public:
    void moveZeroes(std::vector<int>& nums)
    {
        /* BEGIN YOUR CODE HERE */

        // TODO: Move zero values to the end in place.
        int n = nums.size();
        int last_non_zero_index = 0;


        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                std::swap(nums[last_non_zero_index], nums[i]);
                ++last_non_zero_index;
            }
        }

        /* END YOUR CODE HERE */
    }
};

static bool run_test(const std::string& name,
                     std::vector<int> nums,
                     const std::vector<int>& expected)
{
    Solution solution;
    solution.moveZeroes(nums);

    const bool pass = nums == expected;
    std::cout << name << ": " << (pass ? "PASS" : "FAIL") << "\n  got:      [";
    for (std::size_t i = 0; i < nums.size(); ++i) {
        std::cout << (i == 0 ? "" : ", ") << nums[i];
    }
    std::cout << "]\n  expected: [";
    for (std::size_t i = 0; i < expected.size(); ++i) {
        std::cout << (i == 0 ? "" : ", ") << expected[i];
    }
    std::cout << "]\n";
    return pass;
}

int main()
{
    int passed = 0;
    int total = 0;

    passed += run_test("LeetCode example 1", {0, 1, 0, 3, 12}, {1, 3, 12, 0, 0});
    ++total;
    passed += run_test("Single zero", {0}, {0});
    ++total;
    passed += run_test("Zeros at the front", {0, 0, 5, 6}, {5, 6, 0, 0});
    ++total;
    passed += run_test("No zeros", {4, -2, 7}, {4, -2, 7});
    ++total;
    passed += run_test("All zeros", {0, 0, 0}, {0, 0, 0});
    ++total;
    passed += run_test("Empty vector (extra edge case)", {}, {});
    ++total;

    std::cout << "\n" << passed << "/" << total << " tests passed.\n";
    return passed == total ? 0 : 1;
}
