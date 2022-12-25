#include <iostream>
#include <vector>

using namespace std;

/*
 * 19. Remove Nth Node From End of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 *
 * Follow up:
 * Could you do this in one pass?
 *
 * Solution:
 * Use two pointers to find the n-th node from the end of list.
 */

/**
 * Definition for singly-linked list.

 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        // Move p2 ahead by n steps
        for (int i = 0; i < n; i++) {
            p2 = p2->next;
        }
        // If p2 is already at the end of the list, remove the head
        if (p2 == nullptr) {
            return head->next;
        }
        // Move p1 and p2 forward until p2 reaches the end of the list
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // Remove the nth node
        p1->next = p1->next->next;
        return head;
    }

    void printList(ListNode *head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    int main() {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        printList(head);
        head = removeNthFromEnd(head, 2);
        printList(head);
    }

};