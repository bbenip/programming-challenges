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
    pair<int, int> diameterAndDepthOfBinaryTree(TreeNode* root) {
      if (root == nullptr) {
        return { 0, 0 };
      }

      const auto [diameterOfLeftSubtree, leftDepth] = (
        diameterAndDepthOfBinaryTree(root->left)
      );

      const auto [diameterOfRightSubtree, rightDepth] = (
        diameterAndDepthOfBinaryTree(root->right)
      );

      const int maxSubtreeDiameter = max(
        diameterOfLeftSubtree,
        diameterOfRightSubtree
      );

      const int diameterPassingThroughRoot = leftDepth + rightDepth;

      const int diameter = max(maxSubtreeDiameter, diameterPassingThroughRoot);
      const int depth = max(leftDepth, rightDepth) + 1;

      return { diameter, depth };
    }

  public:
    int diameterOfBinaryTree(TreeNode* root) {
      const auto [diameter, depth] = diameterAndDepthOfBinaryTree(root);

      return diameter;
    }
};
