// LeetCode Problem 11: Container With Most Water
// Difficulty: Medium
// Description: Given an integer array height of length n, where each height[i] represents the height of a vertical line at position i.
//              Find two lines that, together with the x-axis, form a container with the maximum area of water it can store.
//              The area is calculated as min(height[i], height[j]) * (j - i), where i < j.
// Constraints:
//   - n == height.length
//   - 2 <= n <= 10^5
//   - 0 <= height[i] <= 10^4
// Algorithmic Pattern: Two Pointers
//   - Use two pointers starting from the ends of the array, calculate the area, and move the pointer with the smaller height inward.
//     This achieves O(n) time (single pass) and O(1) space, as it optimizes by discarding suboptimal pairs.

#include <vector>
#include <iostream>
#include <algorithm> // For max and min

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Step 1: Get the length of the height array
        int array_length = height.size();

        // Step 2: Initialize variables for the two pointers and maximum area
        int left_pointer = 0; // Start at the left end of the array
        int right_pointer = array_length - 1; // Start at the right end of the array
        int max_area = 0; // To track the maximum area found

        // Step 3: Loop while the left pointer is less than the right pointer
        while (left_pointer < right_pointer) {
            // Step 3.1: Calculate the current height (the minimum of the two lines)
            int current_height;
            if (height[left_pointer] < height[right_pointer]) {
                current_height = height[left_pointer];
            } else {
                current_height = height[right_pointer];
            }

            // Step 3.2: Calculate the current width (distance between pointers)
            int current_width = right_pointer - left_pointer;

            // Step 3.3: Calculate the current area
            int current_area = current_height * current_width;

            // Step 3.4: Update the maximum area if the current area is larger
            if (current_area > max_area) {
                max_area = current_area;
            }

            // Step 3.5: Move the pointer with the smaller height inward
            if (height[left_pointer] < height[right_pointer]) {
                left_pointer++;
            } else {
                right_pointer--;
            }

            // Debug print (commented out)
            // cout << "Left: " << left_pointer << ", Right: " << right_pointer
            //      << ", Height: " << current_height << ", Width: " << current_width
            //      << ", Area: " << current_area << ", Max Area: " << max_area << endl;
        }

        // Step 4: Return the maximum area found
        return max_area;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/
    }
};

int main() {
    Solution solution;

    // Test Case 1: Example from problem (height = [1,8,6,2,5,4,8,3,7])
    vector<int> height_1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test Case 1: height = [1,8,6,2,5,4,8,3,7] -> Max Area: ";
    cout << solution.maxArea(height_1) << endl;

    // Test Case 2: Example from problem (height = [1,1])
    vector<int> height_2 = {1, 1};
    cout << "Test Case 2: height = [1,1] -> Max Area: ";
    cout << solution.maxArea(height_2) << endl;

    // Test Case 3: Symmetric heights (height = [1,2,1])
    vector<int> height_3 = {1, 2, 1};
    cout << "Test Case 3: height = [1,2,1] -> Max Area: ";
    cout << solution.maxArea(height_3) << endl;

    // Test Case 4: Decreasing heights (height = [4,3,2,1,4])
    vector<int> height_4 = {4, 3, 2, 1, 4};
    cout << "Test Case 4: height = [4,3,2,1,4] -> Max Area: ";
    cout << solution.maxArea(height_4) << endl;

    // Test Case 5: Minimum length (height = [1,2])
    vector<int> height_5 = {1, 2};
    cout << "Test Case 5: height = [1,2] -> Max Area: ";
    cout << solution.maxArea(height_5) << endl;

    // Test Case 6: All zeros (height = [0,0,0])
    vector<int> height_6 = {0, 0, 0};
    cout << "Test Case 6: height = [0,0,0] -> Max Area: ";
    cout << solution.maxArea(height_6) << endl;

    // Test Case 7: Large heights (height = [1,10000,1,10000,1])
    vector<int> height_7 = {1, 10000, 1, 10000, 1};
    cout << "Test Case 7: height = [1,10000,1,10000,1] -> Max Area: ";
    cout << solution.maxArea(height_7) << endl;

    return 0;
}
