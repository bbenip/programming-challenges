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
    void preorderTraversal(TreeNode* node, vector<int>& traversal) {
      if (node == nullptr) {
        return;
      }

      traversal.push_back(node->val);
      preorderTraversal(node->left, traversal);
      preorderTraversal(node->right, traversal);
    }

  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> traversal;

      preorderTraversal(root, traversal);

      return traversal;
    }
};
