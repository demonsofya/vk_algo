//leetcode https://leetcode.com/problems/merge-k-sorted-lists/

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
    struct CompareLists_t {
        bool operator()(ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode *current = &dummy;

        std::priority_queue<ListNode *, std::vector<ListNode *>, CompareLists_t> minHeap;

        int lists_sz = lists.size();
        for (int i = 0; i < lists_sz; i++) {
            if (lists[i] != nullptr) 
                minHeap.push(lists[i]);
        }

        while (!minHeap.empty()) {
            ListNode *node = minHeap.top();
            minHeap.pop();

            if (node->next != nullptr)
                minHeap.push(node->next);

            current->next = node;
            current = node;
        }

        current->next = nullptr;
        return dummy.next;
    }
};
