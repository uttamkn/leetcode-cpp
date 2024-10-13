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
    vector<int> rightView;
    q.push(root);
    rightView.push_back(root->val);

    while (!q.empty()) {
      TreeNode *currNode = q.front();
      int rightmostEle =
          101; // no val is above 100 according to the constraints
      if (currNode->left) {
        rightmostEle = currNode->left->val;
        q.push(currNode->left);
      }

      if (currNode->right) {
        rightmostEle = currNode->right->val;
        q.push(currNode->right);
      }

      q.pop();
      if (rightmostEle != 101)
        rightView.push_back(rightmostEle);
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
