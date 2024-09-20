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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> leaf1, leaf2;
    collectLeafValues(root1, leaf1);
    collectLeafValues(root2, leaf2);
    return leaf1 == leaf2;
  }

private:
  void collectLeafValues(TreeNode *root, vector<int> &leaf) {
    if (!root)
      return;
    collectLeafValues(root->left, leaf);
    collectLeafValues(root->right, leaf);
    if (!root->left && !root->right)
      leaf.push_back(root->val);
  };
};

int main() {
  Solution sol;
  return 0;
}