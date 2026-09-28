/*
 * LeetCode 26: Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Given an integer array sorted in non-decreasing order, remove duplicates
 * in-place so that each unique value appears once. Preserve the order of the
 * unique values and return k, the number of unique values. The first k entries
 * of nums must contain the result; entries after that can be ignored.
 *
 * This standalone C scaffold includes a small local test harness. Implement
 * removeDuplicates in the marked section. The tests check only the first k
 * entries, matching the problem's custom judge.
 */

#include <stdio.h>

/* BEGIN YOUR CODE HERE */

int removeDuplicates(int nums[], int numsSize)
{
    if (numsSize == 0) {
        return 0;
    }

    int replace = 1; // Index to place the next unique element
    for (int i = 1; i < numsSize; i++) {
        if (nums[i-1] != nums[i]) {
            nums[replace] = nums[i];
            replace++;
        }
    }
    return replace;
   
}

/* END YOUR CODE HERE */

static int run_test(const char *name,
                    const int input[],
                    int numsSize,
                    const int expected[],
                    int expectedSize)
{
    int nums[32];

    if (numsSize > (int)(sizeof nums / sizeof nums[0])) {
        printf("%s: FAIL (test array is too large)\n", name);
        return 0;
    }

    for (int i = 0; i < numsSize; ++i) {
        nums[i] = input[i];
    }

    int resultSize = removeDuplicates(nums, numsSize);
    int pass = resultSize == expectedSize;

    if (pass) {
        for (int i = 0; i < expectedSize; ++i) {
            if (nums[i] != expected[i]) {
                pass = 0;
                break;
            }
        }
    }

    printf("%s: %s (returned k=%d; expected k=%d; prefix=[",
           name, pass ? "PASS" : "FAIL", resultSize, expectedSize);
    for (int i = 0; i < resultSize && i < numsSize; ++i) {
        printf("%s%d", i == 0 ? "" : ", ", nums[i]);
    }
    printf("])\n");
    return pass;
}

int main(void)
{
    int passed = 0;
    int total = 0;

    {
        const int input[] = {1, 1, 2};
        const int expected[] = {1, 2};
        passed += run_test("LeetCode example 1", input, 3, expected, 2);
        ++total;
    }

    {
        const int input[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        const int expected[] = {0, 1, 2, 3, 4};
        passed += run_test("LeetCode example 2", input, 10, expected, 5);
        ++total;
    }

    {
        const int input[] = {-5, -5, -1, 0, 0, 7};
        const int expected[] = {-5, -1, 0, 7};
        passed += run_test("Negative values", input, 6, expected, 4);
        ++total;
    }

    {
        const int input[] = {4, 4, 4, 4};
        const int expected[] = {4};
        passed += run_test("All values equal", input, 4, expected, 1);
        ++total;
    }

    {
        const int input[] = {9};
        const int expected[] = {9};
        passed += run_test("Single element", input, 1, expected, 1);
        ++total;
    }

    {
        const int input[] = {1, 2, 3, 4};
        const int expected[] = {1, 2, 3, 4};
        passed += run_test("No duplicates", input, 4, expected, 4);
        ++total;
    }

    {
        const int input[] = {0};
        const int expected[] = {0};
        passed += run_test("Empty array", input, 0, expected, 0);
        ++total;
    }

    printf("\n%d/%d tests passed.\n", passed, total);
    return passed == total ? 0 : 1;
}
