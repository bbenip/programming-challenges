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
    int minDepth(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }

      const bool isLeftChild = root->left != nullptr;
      const bool isRightChild = root->right != nullptr;
      const bool isAnyChild = isLeftChild || isRightChild;

      if (!isAnyChild) {
        return 1;
      }

      int minimumDepth = INT_MAX;

      if (isLeftChild) {
        minimumDepth = min(minimumDepth, minDepth(root->left));
      }

      if (isRightChild) {
        minimumDepth = min(minimumDepth, minDepth(root->right));
      }

      return minimumDepth + 1;
    }
};
