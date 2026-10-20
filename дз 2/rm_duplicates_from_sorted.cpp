// leetcode
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = nullptr;

    while (slow != nullptr && slow->next != nullptr) {
      fast = slow->next;

      while (fast != nullptr && fast->val == slow->val) {
        fast = fast->next;
      }

      slow->next = fast;
      slow = fast;
    }

    return head;
  }
};