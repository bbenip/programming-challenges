/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  private:
    void getLeaves(TreeNode* node, vector<int>& leaves) {
      if (node == nullptr) {
        return;
      }

      const bool isLeaf = node->left == nullptr && node->right == nullptr;

      if (isLeaf) {
        leaves.push_back(node->val);
      }

      getLeaves(node->left, leaves);
      getLeaves(node->right, leaves);
    }

    vector<int> getLeaves(TreeNode* root) {
      vector<int> leaves;
      getLeaves(root, leaves);

      return leaves;
    }

  public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int> leaves1 = getLeaves(root1);
      vector<int> leaves2 = getLeaves(root2);

      return leaves1 == leaves2;
    }
};
