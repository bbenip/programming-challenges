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
    TreeNode* mergeTrees(const TreeNode* root1, const TreeNode* root2) {
      if (root1 == nullptr && root2 == nullptr) {
        return nullptr;
      }

      const int value1 = root1 == nullptr ? 0 : root1->val;
      const int value2 = root2 == nullptr ? 0 : root2->val;
      const int sum = value1 + value2;

      const TreeNode* leftNode1 = root1 == nullptr ? nullptr : root1->left;
      const TreeNode* leftNode2 = root2 == nullptr ? nullptr : root2->left;
      TreeNode* mergedLeftSubtree = mergeTrees(leftNode1, leftNode2);

      const TreeNode* rightNode1 = root1 == nullptr ? nullptr : root1->right;
      const TreeNode* rightNode2 = root2 == nullptr ? nullptr : root2->right;
      TreeNode* mergedRightSubtree = mergeTrees(rightNode1, rightNode2);

      TreeNode* mergedTree = new TreeNode(
        sum,
        mergedLeftSubtree,
        mergedRightSubtree
      );

      return mergedTree;
    }
};
