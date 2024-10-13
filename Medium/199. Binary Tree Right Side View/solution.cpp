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
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> q;
    q.push(root);
    vector<int> rightView;

    while (!q.empty()) {
      int n = q.size();
      int val;

      for (int i = 0; i < n; ++i) {
        TreeNode *currNode = q.front();
        q.pop();
        val = currNode->val;

        if (currNode->left)
          q.push(currNode->left);

        if (currNode->right)
          q.push(currNode->right);
      }
      rightView.push_back(val);
    }

    return rightView;
  }
};

int main() {
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  vector<int> rightView = solution.rightSideView(root);
  for (int i = 0; i < rightView.size(); i++) {
    cout << rightView[i] << " ";
  }
  return 0;
}
