/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:
    bool checkTree(TreeNode* root) {
      const int leftChildValue = root->left->val;
      const int rightChildValue = root->right->val;
      const int childrenSum = leftChildValue + rightChildValue;

      return root->val == childrenSum;
    }
};
