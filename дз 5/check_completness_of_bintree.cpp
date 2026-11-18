//leetcode https://leetcode.com/problems/check-completeness-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        std::queue<TreeNode *> q;
        q.push(root);

        bool isSeenNull = false;

        while (q.size() > 0) {
            TreeNode *curr_node = q.front();
            q.pop();

            if (curr_node == nullptr)
                isSeenNull = true;
            else {
                if (isSeenNull)
                    return false;

                q.push(curr_node->left);
                q.push(curr_node->right);
            }
        }

        return true;
    }
};
