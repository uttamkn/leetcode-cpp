#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return nullptr;

    TreeNode *cur = root, *parent = nullptr;
    while (cur) {
      if (cur->val == key)
        break;

      parent = cur;

      if (cur->val < key)
        cur = cur->right;
      else
        cur = cur->left;
    }

    if (!cur)
      return root;

    if (!cur->left && !cur->right) {
      if (cur == root) {
        return nullptr;
      }

      attachToParent(parent, cur, nullptr);

      delete cur;
      cur = nullptr;

      return root;
    }

    if (!cur->left || !cur->right) {
      if (cur == root) {
        if (!cur->left)
          return cur->right;
        else
          return cur->left;
      }

      if (!cur->left)
        attachToParent(parent, cur, cur->right);

      if (!cur->right)
        attachToParent(parent, cur, cur->left);

      delete cur;
      cur = nullptr;
      return root;
    }

    TreeNode *runner = cur->right;
    while (runner->left) {
      runner = runner->left;
    }
    runner->left = cur->left;

    if (cur == root) {
      TreeNode *temp = cur->right;
      delete cur;
      cur = nullptr;

      return temp;
    }

    attachToParent(parent, cur, cur->right);
    delete cur;
    cur = nullptr;

    return root;
  }

  void printTree(TreeNode *root) {
    if (!root)
      return;

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
  }

private:
  void attachToParent(TreeNode *parent, TreeNode *target, TreeNode *node) {
    if (parent->left == target)
      parent->left = node;
    else
      parent->right = node;
  }
};

int main() {
  Solution solution;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  solution.deleteNode(root, 3);

  solution.printTree(root);
  return 0;
}
