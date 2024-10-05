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

// Time Complexity: O(n^2)
// class Solution {
// public:
//   int pathSum(TreeNode *root, int targetSum) { return helper(root,
//   targetSum); }
//
// private:
//   int helper(TreeNode *root, int targetSum) {
//     if (root == nullptr) {
//       return 0;
//     }
//     return dfs(root, targetSum, 0) + helper(root->left, targetSum) +
//            helper(root->right, targetSum);
//   }
//
//   int dfs(TreeNode *root, int targetSum, long curSum) {
//     if (root == nullptr) {
//       return 0;
//     }
//
//     curSum += root->val;
//
//     int count = (curSum == targetSum) ? 1 : 0;
//
//     return count + dfs(root->left, targetSum, curSum) +
//            dfs(root->right, targetSum, curSum);
//   }
// };

// Time Complexity: O(n) using prefix sum (check readme)
class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    map<long, int> mp;
    mp[0]++;
    return helper(root, targetSum, mp, 0);
  }

private:
  int helper(TreeNode *root, int targetSum, map<long, int> &mp, long curSum) {
    if (!root) {
      return 0;
    }

    curSum += root->val;
    int count = mp[curSum - targetSum];
    mp[curSum]++;

    count += helper(root->left, targetSum, mp, curSum);
    count += helper(root->right, targetSum, mp, curSum);

    mp[curSum]--;

    return count;
  }
};

int main() {
  Solution solution;
  // TreeNode *root = new TreeNode(10);
  // root->left = new TreeNode(5);
  // root->right = new TreeNode(-3);
  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(2);
  // root->right->right = new TreeNode(11);
  // root->left->left->left = new TreeNode(3);
  // root->left->left->right = new TreeNode(-2);
  // root->left->right->right = new TreeNode(1);
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(1);
  cout << solution.pathSum(root, 1) << endl;
  if (solution.pathSum(root, 1) == 4) {
    cout << "Passed" << endl;
  } else {
    cout << "Failed" << endl;
  }
  return 0;
}
