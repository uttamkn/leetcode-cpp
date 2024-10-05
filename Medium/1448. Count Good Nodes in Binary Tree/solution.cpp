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
  int goodNodes(TreeNode *root) { return dfs(root, INT_MIN); }

private:
  int dfs(TreeNode *root, int curMax) {
    if (root == nullptr)
      return 0;

    if (root->val > curMax) {
      curMax = root->val;
    }

    if (root->val >= curMax) {
      return 1 + dfs(root->left, curMax) + dfs(root->right, curMax);
    } else
      return dfs(root->left, curMax) + dfs(root->right, curMax);
  }
};

int main() {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(5);
  cout << sol.goodNodes(root) << endl;
  if (sol.goodNodes(root) == 4) {
    std::cout << "Test passed!" << std::endl;
  } else {
    std::cout << "Test failed!" << std::endl;
  }
}
