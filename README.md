# LeetCode Solutions Repository

This repository contains my solutions to LeetCode problems, implemented in C++ and organized into three folders based on difficulty: `Easy`, `Medium`, and `Hard`. Each problem’s solution includes a `main()` function that injects LeetCode test cases, enabling easy execution and verification in Visual Studio Code on a Windows environment.

## Structure
- **Easy/**: Solutions to LeetCode problems classified as Easy.
- **Medium/**: Solutions to LeetCode problems classified as Medium.
- **Hard/**: Solutions to LeetCode problems classified as Hard.

Each solution file (`.cpp`) contains:
- The LeetCode problem description in a header comment.
- The solution code within a `Solution` class.
- A `main()` function that runs predefined test cases and prints results.

## Common Problem Patterns
LeetCode problems often follow recurring algorithmic patterns. The solutions in this repository typically fall into one of the following categories:
1. **Prefix Sum**: Using cumulative sums to solve array-based problems efficiently.
2. **Two Pointers**: Employing two indices to traverse arrays or lists, often for searching or partitioning.
3. **Sliding Window**: Maintaining a dynamic window of elements to solve substring or subarray problems.
4. **Fast & Slow Pointers**: Using two pointers at different speeds, commonly for cycle detection or finding midpoints in linked lists.
5. **LinkedList In-place Reversal**: Reversing linked list segments without extra space.
6. **Monotonic Stack**: Using a stack to maintain elements in a specific order (increasing or decreasing).
7. **Top ‘K’ Elements**: Finding the top K elements using heaps or sorting techniques.
8. **Overlapping Intervals**: Managing intervals to merge, intersect, or schedule tasks.
9. **Modified Binary Search**: Adapting binary search for rotated arrays or finding boundaries.
10. **Binary Tree Traversal**: Traversing trees using inorder, preorder, or postorder methods.
11. **Depth-First Search (DFS)**: Exploring graphs or trees by diving deep into each branch.
12. **Breadth-First Search (BFS)**: Exploring graphs or trees level by level.
13. **Matrix Traversal**: Navigating 2D arrays using row-wise, column-wise, or spiral patterns.
14. **Backtracking**: Exploring all possible solutions, typically for combinatorial problems.
15. **Dynamic Programming Patterns**: Solving problems by breaking them into overlapping subproblems, using memoization or tabulation.

## Running the Solutions
- **Environment**: Windows, using Visual Studio Code.
- **Compile**: Use `g++` (e.g., `g++ Easy/two_sum.cpp -o Easy/two_sum`).
- **Run**: Execute the binary (e.g., `.\Easy\two_sum`) to see test case outputs.
- **Git**: Executables are ignored via `.gitignore` to keep the repository clean.