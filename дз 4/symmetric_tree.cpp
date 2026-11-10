// leetcode https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    std::vector<TreeNode *> v{root};
    while (v.size() > 0) {
      int v_size = v.size();
      for (int i = 0; i < v_size; i++) {
        if (v[i] == nullptr && v[v_size - i - 1] == nullptr) {
          continue;
        }
        if (v[i] == nullptr || v[v_size - i - 1] == nullptr) {
          return false;
        }
        if (v[i]->val != v[v_size - i - 1]->val) {
          return false;
        }

        v.push_back(v[i]->left);
        v.push_back(v[i]->right);
      }

      v.erase(v.begin(), v.begin() + v_size);
    }

    return true;
  }
};