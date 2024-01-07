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
    void tree2str(TreeNode* root, string& result) {
      if (root == nullptr) {
        return;
      }

      result += to_string(root->val);

      if (root->left != nullptr || root->right != nullptr) {
        result += '(';
        tree2str(root->left, result);
        result += ')';
      }

      if (root->right != nullptr) {
        result += '(';
        tree2str(root->right, result);
        result += ')';
      }
    }

  public:
    string tree2str(TreeNode* root) {
      string result = "";
      tree2str(root, result);

      return result;
    }
};
