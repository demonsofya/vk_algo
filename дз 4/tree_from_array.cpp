#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
  TreeNode(int val_, TreeNode *left_, TreeNode *right_)
      : val(val_), left(left_), right(right_) {}

  void print() const { // this method is full vibecoding 'cause i was too lazy
                       // to make a printout func by my own but i need to test
                       // this programm somehow
    std::queue<const TreeNode *> q;
    q.push(this);

    while (!q.empty()) {
      int level_sz = q.size();
      bool has_children = false;

      for (int i = 0; i < level_sz; i++) {
        const TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
          std::cout << "- ";
          continue;
        }

        std::cout << node->val << ' ';

        q.push(node->left);
        q.push(node->right);

        if (node->left != nullptr || node->right != nullptr)
          has_children = true;
      }

      std::cout << '\n';

      if (!has_children)
        break;
    }
  }

  int val;
  TreeNode *left;
  TreeNode *right;
};

TreeNode *buildTree(std::vector<int> v, int i) {
  if (i >= v.size())
    return nullptr;

  TreeNode *root = new TreeNode(v[i]);
  root->left = buildTree(v, 2 * i + 1);
  root->right = buildTree(v, 2 * i + 2);

  return root;
}

int main() {
  std::vector<int> v{21, 19, 18, 11, 12, 15, 16, 9, 8, 10};
  TreeNode *root = buildTree(v, 0);

  root->print();
  return 0;
}