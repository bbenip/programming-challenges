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
    bool isSymmetric(TreeNode* root) {
      TreeNode* leftChild = root->left;
      TreeNode* rightChild = root->right;

      return isSymmetric(leftChild, rightChild);
    }

    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
      if (root1 == nullptr && root2 == nullptr) {
        return true;
      }

      if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
        return false;
      }

      return (
        isSymmetric(root1->left, root2->right) &&
        isSymmetric(root1->right, root2->left)
      );
    }
};
