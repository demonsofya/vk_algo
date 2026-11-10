// leetcode https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;

    std::vector<TreeNode *> v{root};
    int h = 1;
    while (v.size() > 0) {
      int v_size = v.size();
      for (int i = 0; i < v_size; i++) {
        if (v[i]->left == nullptr && v[i]->right == nullptr) {
          return h;
        }

        if (v[i]->left != nullptr)
          v.push_back(v[i]->left);
        if (v[i]->right != nullptr)
          v.push_back(v[i]->right);
      }

      h++;
      v.erase(v.begin(), v.begin() + v_size);
    }

    return h;
    // if (root == nullptr)
    //     return 0;

    // if (root->left == nullptr && root->right == nullptr)
    //     return 1;

    // if (root->left != nullptr && root->right != nullptr)
    //     return 1 + std::min(minDepth(root->left), minDepth(root->right));

    // if (root->left != nullptr)
    //     return 1 + minDepth(root->left);

    // return 1 + minDepth(root->right);
  }
};