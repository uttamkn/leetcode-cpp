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
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int currMax = INT_MIN;
    int currLevel = 0;
    int maxLevel = 0;

    while (!q.empty()) {
      int n = q.size();
      int levelSum = 0;

      for (int i = 0; i < n; ++i) {
        TreeNode *currNode = q.front();
        q.pop();

        levelSum += currNode->val;

        if (currNode->left)
          q.push(currNode->left);

        if (currNode->right)
          q.push(currNode->right);
      }

      currLevel++;
      if (currMax < levelSum) {
        currMax = levelSum;
        maxLevel = currLevel;
      }
    }

    return maxLevel;
  }
};

int main() {
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);

  cout << solution.maxLevelSum(root);
  return 0;
}
