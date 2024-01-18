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

      if (root != nullptr) {
        nodes.push(root);
      }

      nodes.push(nullptr);

      vector<int> level;

      while (!nodes.empty()) {
        if (nodes.size() == 1) {
          if (!level.empty()) {
            traversal.push_back(level);
            level.clear();
          }

          break;
        }

        TreeNode* currentNode = nodes.front();
        nodes.pop();

        if (currentNode == nullptr) {
          traversal.push_back(level);
          level.clear();

          nodes.push(nullptr);
        } else {
          level.push_back(currentNode->val);

          if (currentNode->left != nullptr) {
            nodes.push(currentNode->left);
          }

          if (currentNode->right != nullptr) {
            nodes.push(currentNode->right);
          }
        }
      }

      return traversal;
    }
};
