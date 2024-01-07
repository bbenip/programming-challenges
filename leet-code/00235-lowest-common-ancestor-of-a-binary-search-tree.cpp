/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      const int smallerValue = min(p->val, q->val);
      const int largerValue = max(p->val, q->val);

      TreeNode* node = root;

      while (node != nullptr) {
        const int currentValue = node->val;

        if (smallerValue <= currentValue && currentValue <= largerValue) {
          return node;
        }

        if (currentValue > largerValue) {
          node = node->left;
        } else {
          node = node->right;
        }
      }

      return nullptr;
    }
};
