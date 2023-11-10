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
  private:
    int depthOfBinaryTree(TreeNode* root, int& diameter) {
      if (root == nullptr) {
        return 0;
      }

      const int leftDepth = depthOfBinaryTree(root->left, diameter);
      const int rightDepth = depthOfBinaryTree(root->right, diameter);

      diameter = max(diameter, leftDepth + rightDepth);

      return max(leftDepth, rightDepth) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode* root) {
      int diameter = 0;
      depthOfBinaryTree(root, diameter);

      return diameter;
    }
};
