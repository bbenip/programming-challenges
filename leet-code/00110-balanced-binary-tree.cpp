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
    int getDepthOfTreeAndCheckBalance(TreeNode* root, bool& isTreeBalanced) {
      if (root == nullptr) {
        return 0;
      }

      const int leftDepth = getDepthOfTreeAndCheckBalance(
        root->left,
        isTreeBalanced
      );

      const int rightDepth = getDepthOfTreeAndCheckBalance(
        root->right,
        isTreeBalanced
      );

      if (abs(leftDepth - rightDepth) > 1) {
        isTreeBalanced = false;
      }

      return max(leftDepth, rightDepth) + 1;
    }

  public:
    bool isBalanced(TreeNode* root) {
      bool isTreeBalanced = true;

      getDepthOfTreeAndCheckBalance(root, isTreeBalanced);

      return isTreeBalanced;
    }
};
