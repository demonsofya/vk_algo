// leetcode https://leetcode.com/problems/merge-two-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *first = list1;
    ListNode *second = list2;

    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;

    while (first != nullptr && second != nullptr) {
      if (first->val < second->val) {
        curr->next = first;
        first = first->next;
      } else {
        curr->next = second;
        second = second->next;
      }

      curr = curr->next;
    }

    while (first != nullptr) {
      curr->next = first;

      curr = curr->next;
      first = first->next;
    }

    while (second != nullptr) {
      curr->next = second;

      curr = curr->next;
      second = second->next;
    }

    return dummy->next;
  }
};