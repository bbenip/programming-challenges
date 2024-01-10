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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      TreeNode* newNode = new TreeNode(val);

      if (root == nullptr) {
        return newNode;
      }

      TreeNode* currentNode = root;

      while (currentNode != nullptr) {
        if (val > currentNode->val) {
          if (currentNode->right == nullptr) {
            currentNode->right = newNode;
            break;
          }

          currentNode = currentNode->right;
        } else {
          if (currentNode->left == nullptr) {
            currentNode->left = newNode;
            break;
          }

          currentNode = currentNode->left;
        }
      }

      return root;
    }
};
