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
  int max = 0;

public:
  int maxdepth(TreeNode *root) {
    traversal(root, 0);
    return max;
  }

private:
  void traversal(TreeNode *root, int cur) {
    if (!root)
      return;
    cur++;
    traversal(root->left, cur);
    traversal(root->right, cur);
    max = (cur > max) ? cur : max;
  }
};

int main() {
  Solution sol;
  return 0;
}
