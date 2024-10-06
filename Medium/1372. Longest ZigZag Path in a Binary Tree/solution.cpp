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
  int longestZigZag(TreeNode *root) {
    int maxLen = 0;

    getMaxZigZag(root, false, 0, maxLen);
    getMaxZigZag(root, true, 0, maxLen);

    return maxLen - 1;
  }

private:
  void getMaxZigZag(TreeNode *root, bool goRight, int len, int &maxLen) {
    if (!root)
      return;

    len++;
    if (!goRight) {
      maxLen = max(maxLen, len);
      getMaxZigZag(root->left, false, 1, maxLen);

      getMaxZigZag(root->right, true, len, maxLen);
    } else if (goRight) {
      maxLen = max(maxLen, len);
      getMaxZigZag(root->right, true, 1, maxLen);

      getMaxZigZag(root->left, false, len, maxLen);
    }
  }
};

int main() {
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(1);
  root->right->right->left = new TreeNode(1);
  root->right->right->right = new TreeNode(1);
  root->right->right->left->right = new TreeNode(1);
  root->right->right->left->right->right = new TreeNode(1);
  cout << solution.longestZigZag(root) << endl;
  if (solution.longestZigZag(root) == 3) {
    cout << "Test case passed!" << endl;
  } else {
    cout << "Test case failed!" << endl;
  }
  return 0;
}
