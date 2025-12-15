# LeetCode Problem 2: Add Two Numbers
# Difficulty: Medium
# Description: Given two non-empty linked lists representing non-negative integers (digits in reverse order),
#              add the two numbers and return the sum as a linked list. Each node contains a single digit.
#              Assume no leading zeros except for the number 0 itself.
# Constraints:
#   - Number of nodes in each list: [1, 100]
#   - 0 <= Node.val <= 9
#   - No leading zeros except for 0
# Algorithmic Pattern: Linked List Traversal + Math
#   - Traverse both lists simultaneously, add digits with carry, create new nodes for the result.
#     Handle remaining nodes and final carry. Achieves O(max(m,n)) time and O(max(m,n)) space.

from typing import Optional

# Definition for singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Adds two numbers represented as linked lists and returns the sum as a linked list.
        """
        # ------------------------------
        # BEGIN YOUR CODE HERE
        # ------------------------------

        # Step 1: Initialize a dummy node to simplify result list creation
        dummy_head = ListNode(0)
        current = dummy_head
        carry = 0  # Carry for the next digit

        # Step 2: Traverse both lists until both are exhausted and no carry remains
        while l1 is not None or l2 is not None or carry != 0:
            # Step 2.1: Get values from current nodes, use 0 if node is None
            val1 = l1.val if l1 is not None else 0
            val2 = l2.val if l2 is not None else 0

            # Step 2.2: Calculate sum and new carry
            total = val1 + val2 + carry
            carry = total // 10  # Integer division for carry (0 or 1)
            digit = total % 10   # Remainder for current digit

            # Step 2.3: Create new node with the digit and advance current pointer
            current.next = ListNode(digit)
            current = current.next

            # Step 2.4: Advance l1 and l2 pointers if they are not None
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next

        # Step 3: Return the result list, skipping the dummy node
        return dummy_head.next

        # ------------------------------
        # END YOUR CODE HERE
        # ------------------------------

# Helper function to create a linked list from a list of integers
def create_linked_list(values: list) -> Optional[ListNode]:
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Helper function to convert a linked list to a Python list for printing
def linked_list_to_list(head: Optional[ListNode]) -> list:
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

def main():
    solution = Solution()

    # Test Case 1: Example from problem (l1 = [2,4,3], l2 = [5,6,4])
    l1_1 = create_linked_list([2, 4, 3])
    l2_1 = create_linked_list([5, 6, 4])
    print(f"Test Case 1: l1 = [2,4,3], l2 = [5,6,4] -> Sum: {linked_list_to_list(solution.addTwoNumbers(l1_1, l2_1))}")

    # Test Case 2: Example from problem (l1 = [0], l2 = [0])
    l1_2 = create_linked_list([0])
    l2_2 = create_linked_list([0])
    print(f"Test Case 2: l1 = [0], l2 = [0] -> Sum: {linked_list_to_list(solution.addTwoNumbers(l1_2, l2_2))}")

    # Test Case 3: Example from problem (l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9])
    l1_3 = create_linked_list([9, 9, 9, 9, 9, 9, 9])
    l2_3 = create_linked_list([9, 9, 9, 9])
    print(f"Test Case 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9] -> Sum: {linked_list_to_list(solution.addTwoNumbers(l1_3, l2_3))}")

    # Test Case 4: Single digit with carry (l1 = [9], l2 = [1])
    l1_4 = create_linked_list([9])
    l2_4 = create_linked_list([1])
    print(f"Test Case 4: l1 = [9], l2 = [1] -> Sum: {linked_list_to_list(solution.addTwoNumbers(l1_4, l2_4))}")

    # Test Case 5: Different lengths (l1 = [1,2,3], l2 = [4])
    l1_5 = create_linked_list([1, 2, 3])
    l2_5 = create_linked_list([4])
    print(f"Test Case 5: l1 = [1,2,3], l2 = [4] -> Sum: {linked_list_to_list(solution.addTwoNumbers(l1_5, l2_5))}")

    # Test Case 6: Maximum carry propagation (l1 = [9,9,9], l2 = [1])
    l1_6 = create_linked_list([9, 9, 9])
    l2_6 = create_linked_list([1])
    print(f"Test Case 6: l1 = [9,9,9], l2 = [1] -> Sum: {linked_list_to_list(solution.addTwoNumbers(l1_6, l2_6))}")

if __name__ == "__main__":
    main()