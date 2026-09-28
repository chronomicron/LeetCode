/*
 * LeetCode 1480: Running Sum of 1d Array
 *
 * Problem summary:
 * Given an integer array, produce an array where each element is the sum of
 * the input elements from index 0 through that element's index.
 *
 * Source: https://leetcode.com/problems/running-sum-of-1d-array/
 *
 * This standalone C harness supplies test arrays and checks the result. Type
 * your implementation between BEGIN YOUR CODE HERE and END YOUR CODE HERE.
 * The C function signature follows LeetCode's C interface. C has no
 * "Solution" class, and a hosted C program uses int main(void).
 *
 * Compile from a terminal:
 *   gcc -std=c11 -Wall -Wextra -Wpedantic -g running_sum.c -o running_sum
 * Run:
 *   ./running_sum
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int *runningSum(int *nums, int numsSize, int *returnSize)
{
    if (returnSize == NULL) {
        return NULL;
    }

    *returnSize = 0;

    if (numsSize < 0 || (numsSize > 0 && nums == NULL)) {
        return NULL;
    }

    /************************/
    /* BEGIN YOUR CODE HERE */
    /************************/
    /*
     * TODO:
     *   1. Produce the running sums.
     *   2. Set *returnSize to the number of returned elements.
     *   3. Return the result array.
     *
     * The test harness calls free() on a returned array when it is separate
     * from the input array. Returning NULL for now keeps this starter file
     * safe to compile and run before the implementation is added.
     */


    int sum = 0;
    
    int *result = malloc(numsSize * sizeof(int));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
   
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        result[i] = sum;
    }

    *returnSize = numsSize;
    return result;

    /**********************/
    /* END YOUR CODE HERE */
    /**********************/
}

static void print_array(const int values[], int count)
{
    printf("[");
    for (int i = 0; i < count; ++i) {
        printf("%d", values[i]);
        if (i + 1 < count) {
            printf(", ");
        }
    }
    printf("]");
}

static int arrays_equal(const int actual[], const int expected[], int count)
{
    for (int i = 0; i < count; ++i) {
        if (actual[i] != expected[i]) {
            return 0;
        }
    }
    return 1;
}

static int run_test(const char *name,
                    int input[],
                    int inputSize,
                    const int expected[],
                    int expectedSize)
{
    int actualSize = -1;
    int *actual = runningSum(input, inputSize, &actualSize);

    int passed = (actualSize == expectedSize);
    if (passed && expectedSize > 0 && actual == NULL) {
        passed = 0;
    }
    if (passed && expectedSize > 0 &&
        !arrays_equal(actual, expected, expectedSize)) {
        passed = 0;
    }

    printf("%s: %s\n", name, passed ? "PASS" : "FAIL");

    printf("  input:    ");
    print_array(input, inputSize);
    printf("\n  expected: ");
    print_array(expected, expectedSize);
    printf("\n  actual:   ");

    if (actual == NULL && actualSize == 0) {
        printf("[]");
    } else if (actual == NULL) {
        printf("NULL (reported length %d)", actualSize);
    } else if (actualSize < 0) {
        printf("invalid length %d", actualSize);
    } else {
        print_array(actual, actualSize);
    }
    printf("\n");

    /*
     * The solution should normally return a separately allocated result.
     * This check also permits an in-place solution that returns the input.
     */
    if (actual != NULL && actual != input) {
        free(actual);
    }

    return passed;
}

int main(void)
{
    int nums1[] = {1, 2, 3, 4};
    const int expected1[] = {1, 3, 6, 10};

    int nums2[] = {1, 1, 1, 1, 1};
    const int expected2[] = {1, 2, 3, 4, 5};

    int nums3[] = {3, 1, 2, 10, 1};
    const int expected3[] = {3, 4, 6, 16, 17};

    int nums4[] = {42};
    const int expected4[] = {42};

    int nums5[] = {-2, 0, 3, -1};
    const int expected5[] = {-2, -2, 1, 0};

    int nums6[] = {0, 0, 0};
    const int expected6[] = {0, 0, 0};

    int passed = 0;
    int total = 0;

#define RUN_TEST(name, input, input_size, expected, expected_size) \
    do { \
        passed += run_test((name), (input), (input_size), \
                           (expected), (expected_size)); \
        ++total; \
        printf("\n"); \
    } while (0)

    RUN_TEST("LeetCode example 1", nums1, 4, expected1, 4);
    RUN_TEST("LeetCode example 2", nums2, 5, expected2, 5);
    RUN_TEST("LeetCode example 3", nums3, 5, expected3, 5);
    RUN_TEST("Single element", nums4, 1, expected4, 1);
    RUN_TEST("Negative and zero values", nums5, 4, expected5, 4);
    RUN_TEST("All zeros", nums6, 3, expected6, 3);
    RUN_TEST("Empty input", NULL, 0, NULL, 0);

#undef RUN_TEST

    printf("Summary: %d/%d tests passed.\n", passed, total);
    return (passed == total) ? EXIT_SUCCESS : EXIT_FAILURE;
}
