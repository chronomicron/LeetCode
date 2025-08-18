// LeetCode: 2. Add Two Numbers
// Description:
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single
// digit. Add the two numbers and return the sum as a linked list. You may assume the
// two numbers do not contain any leading zero, except the number 0 itself.
//
// Constraints:
// - The number of nodes in each linked list is in the range [1, 100].
// - 0 <= Node.val <= 9
// - It is guaranteed that the list represents a number that does not have leading zeros.
//
// Test Cases:
// 1. Input: l1 = [2,4,3], l2 = [5,6,4]
//    Output: [7,0,8] (Explanation: 342 + 465 = 807)
// 2. Input: l1 = [0], l2 = [0]
//    Output: [0] (Explanation: 0 + 0 = 0)
// 3. Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//    Output: [8,9,9,9,0,0,0,1] (Explanation: 9999999 + 9999 = 10009998)

#include <iostream>          // For input/output operations
#include <vector>            // For test case arrays

using std::vector;
using std::cout;
using std::endl;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        /************************/
        /* BEGIN YOUR CODE HERE */
        /************************/

        // Initialize dummy node and current pointer
        ListNode* topList = new ListNode(0);
        ListNode* current = topList;
        int carry = 0;

        // Process lists and carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values, use 0 if list is exhausted
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            // Calculate sum and carry
            int sum = x + y + carry;
            carry = sum / 10;
            // Create new node with digit
            current->next = new ListNode(sum % 10);
            current = current->next;
            // Advance pointers if available
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        // Return result, skipping dummy node
        return topList->next;

        /**********************/
        /* END YOUR CODE HERE */
        /**********************/

    }
};

// Helper function to build a linked list from a vector
ListNode* buildList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]";
}

// Helper function to free a linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create Solution object
    Solution sol;

    // Test case 1: l1 = [2,4,3], l2 = [5,6,4]
    vector<int> nums1 = {2, 4, 3};
    vector<int> nums2 = {5, 6, 4};
    ListNode* l1 = buildList(nums1);
    ListNode* l2 = buildList(nums2);
    ListNode* result1 = sol.addTwoNumbers(l1, l2);
    cout << "Input: l1 = ";
    printList(l1);
    cout << ", l2 = ";
    printList(l2);
    cout << ", Output: ";
    printList(result1);
    cout << endl;
    freeList(l1);
    freeList(l2);
    freeList(result1);

    // Test case 2: l1 = [0], l2 = [0]
    nums1 = {0};
    nums2 = {0};
    l1 = buildList(nums1);
    l2 = buildList(nums2);
    result1 = sol.addTwoNumbers(l1, l2);
    cout << "Input: l1 = ";
    printList(l1);
    cout << ", l2 = ";
    printList(l2);
    cout << ", Output: ";
    printList(result1);
    cout << endl;
    freeList(l1);
    freeList(l2);
    freeList(result1);

    // Test case 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    nums1 = {9, 9, 9, 9, 9, 9, 9};
    nums2 = {9, 9, 9, 9};
    l1 = buildList(nums1);
    l2 = buildList(nums2);
    result1 = sol.addTwoNumbers(l1, l2);
    cout << "Input: l1 = ";
    printList(l1);
    cout << ", l2 = ";
    printList(l2);
    cout << ", Output: ";
    printList(result1);
    cout << endl;
    freeList(l1);
    freeList(l2);
    freeList(result1);

    return 0;
}
