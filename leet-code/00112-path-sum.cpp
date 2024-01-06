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
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) {
        return false;
      }

      const bool isLeafNode = (
        root->left == nullptr
        && root->right == nullptr
      );

      const int currentValue = root->val;

      if (isLeafNode && targetSum == currentValue) {
        return true;
      }

      return (
        hasPathSum(root->left, targetSum - currentValue)
        || hasPathSum(root->right, targetSum - currentValue)
      );
    }
};
