/*
 * LeetCode 566: Reshape the Matrix
 * https://leetcode.com/problems/reshape-the-matrix/
 *
 * Reshape a matrix into r rows and c columns while keeping its elements in
 * row-major order. If the requested shape has a different number of elements,
 * the original matrix should be returned unchanged.
 *
 * This standalone C scaffold uses LeetCode's function interface and includes
 * a local test harness. Implement matrixReshape in the marked section.
 */

#include <stdio.h>
#include <stdlib.h>

/* BEGIN YOUR CODE HERE */

int **matrixReshape(int **mat, int matSize, int *matColSize,
                    int r, int c, int *returnSize,
                    int **returnColumnSizes)
{
    const int num_input_rows = matSize;
    const int num_input_cols = matColSize[0];  // assumes a rectangular matrix

    const int num_output_rows = r;
    const int num_output_cols = c;

    // If the requested shape is invalid, return the original matrix.
    if (num_input_rows == 0 || num_input_cols == 0 || num_output_rows <= 0 || num_output_cols <= 0 || num_input_rows * num_input_cols != num_output_rows * num_output_cols) {
        *returnSize = num_input_rows;
        *returnColumnSizes = matColSize;
        return mat;
    }

    // Allocate the returnColumnSizes array and set its values.
    int **output_matrix = malloc((size_t)num_output_rows * sizeof *output_matrix);

    for (int row = 0; row < num_output_rows; ++row) {
        output_matrix[row] = malloc((size_t)num_output_cols * sizeof *output_matrix[row]);
    }

    // output_matrix[row][col] = value;
    int row_num = 0;
    int col_num = 0;
    for (int i = 0; i < num_input_rows; ++i) {
        for (int j = 0; j < num_input_cols; ++j) {
            output_matrix[row_num][col_num] = mat[i][j];
            ++col_num;
            if (col_num == num_output_cols) {
                col_num = 0;
                ++row_num;
            }
        }
    }

    int *output_column_sizes =
        malloc((size_t)num_output_rows * sizeof *output_column_sizes);

    for (int row = 0; row < num_output_rows; ++row) {
        output_column_sizes[row] = num_output_cols;
    }

    *returnSize = num_output_rows;
    *returnColumnSizes = output_column_sizes;
    return output_matrix;


    /*
    // TODO: Allocate and fill the reshaped matrix in row-major order.
    (void)mat;
    (void)matSize;
    (void)matColSize;
    (void)r;
    (void)c;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
    */
}

/* END YOUR CODE HERE */

static int run_test(const char *name,
                    int **mat,
                    int matSize,
                    int *matColSize,
                    int r,
                    int c,
                    const int expected[][6])
{
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = matrixReshape(mat, matSize, matColSize,
                                 r, c, &returnSize, &returnColumnSizes);
    int pass = result != NULL && returnSize == r;

    if (pass) {
        for (int row = 0; row < r && pass; ++row) {
            if (returnColumnSizes == NULL || returnColumnSizes[row] != c) {
                pass = 0;
                break;
            }
            for (int col = 0; col < c; ++col) {
                if (result[row][col] != expected[row][col]) {
                    pass = 0;
                    break;
                }
            }
        }
    }

    printf("%s: %s\n", name, pass ? "PASS" : "FAIL");

    /* These tests request a different, valid shape, so the result is new. */
    if (result != NULL && result != mat) {
        for (int row = 0; row < returnSize; ++row) {
            free(result[row]);
        }
        free(result);
    }
    free(returnColumnSizes);

    return pass;
}

int main(void)
{
    int passed = 0;
    const int total = 3;

    {
        int row0[] = {1, 2};
        int row1[] = {3, 4};
        int row2[] = {5, 6};
        int *mat[] = {row0, row1, row2};
        int matColSize[] = {2, 2, 2};
        const int expected[2][6] = {{1, 2, 3}, {4, 5, 6}};
        passed += run_test("LeetCode example 1", mat, 3, matColSize,
                           2, 3, expected);
    }

    {
        int row0[] = {1, 2};
        int row1[] = {3, 4};
        int *mat[] = {row0, row1};
        int matColSize[] = {2, 2};
        const int expected[1][6] = {{1, 2, 3, 4}};
        passed += run_test("Reshape 2x2 to 1x4", mat, 2, matColSize,
                           1, 4, expected);
    }

    {
        int row0[] = {7, 8, 9, 10};
        int *mat[] = {row0};
        int matColSize[] = {4};
        const int expected[4][6] = {{7}, {8}, {9}, {10}};
        passed += run_test("Reshape 1x4 to 4x1", mat, 1, matColSize,
                           4, 1, expected);
    }

    printf("\n%d/%d tests passed.\n", passed, total);
    return passed == total ? 0 : 1;
}
