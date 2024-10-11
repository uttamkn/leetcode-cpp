#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return lowestCommonAncestor(root, p, q, root);
  }

private:
  bool isAncestor(TreeNode *root, int p, int q, bool isFound[]) {
    if (!root)
      return isFound[0] && isFound[1];

    if (isFound[0] && isFound[1])
      return true;

    if (root->val == p) {
      isFound[0] = true;
    } else if (root->val == q) {
      isFound[1] = true;
    }

    return isAncestor(root->left, p, q, isFound) ||
           isAncestor(root->right, p, q, isFound);
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q,
                                 TreeNode *prev) {
    if (!root)
      return nullptr;

    if (root == q || root == p)
      return prev;

    bool left = isAncestor(root->left, p->val, q->val, (bool[]){false, false});
    bool right =
        isAncestor(root->right, p->val, q->val, (bool[]){false, false});

    if (left) {
      return lowestCommonAncestor(root->left, p, q, root->left);
    }

    if (right) {
      return lowestCommonAncestor(root->right, p, q, root->right);
    }

    return prev;
  }
};

// Using path method (better)
// class Solution {
// public:
//     bool path(TreeNode*root, vector<TreeNode*>&resPath, TreeNode* x) {
//       if(!root) return false;
//       resPath.push_back(root);
//
//       if(root == x) return true;
//
//       if(path(root->left, resPath, x) || path(root->right, resPath, x))
//       return true;
//
//       resPath.pop_back();
//
//       return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//       vector<TreeNode*> p_path, q_path;
//       path(root, p_path, p);
//       path(root, q_path, q);
//
//       int i;
//       for( i = 0; i < p_path.size() && i < q_path.size(); ++i) {
//         if(p_path[i] != q_path[i]) break;
//       }
//
//       return p_path[i-1];
//     }
// };

int main() {
  Solution solution;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode *p = root->left;
  TreeNode *q = root->left->right->right;
  TreeNode *result = solution.lowestCommonAncestor(root, p, q);
  if (result) {
    cout << "result: " << result->val << endl;
  } else {
    cout << "result: nullptr" << endl;
  }
  return 0;
}
