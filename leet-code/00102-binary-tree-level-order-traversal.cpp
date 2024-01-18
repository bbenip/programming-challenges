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
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> traversal;

      queue<TreeNode*> nodes;
      nodes.push(root);

      while (!nodes.empty()) {
        vector<int> level;
        const int size = nodes.size();

        for (int i = 0; i < size; ++i) {
          TreeNode* currentNode = nodes.front();
          nodes.pop();

          if (currentNode == nullptr) {
            continue;
          }

          level.push_back(currentNode->val);

          nodes.push(currentNode->left);
          nodes.push(currentNode->right);
        }

        if (!level.empty()) {
          traversal.push_back(level);
        }
      }

      return traversal;
    }
};
