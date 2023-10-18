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
    void inorderTraversal(TreeNode* node, vector<int>& traversal) {
      if (node == nullptr) {
        return;
      }

      inorderTraversal(node->left, traversal);
      traversal.push_back(node->val);
      inorderTraversal(node->right, traversal);
    }

  public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> traversal;
      inorderTraversal(root, traversal);

      return traversal;
    }
};
