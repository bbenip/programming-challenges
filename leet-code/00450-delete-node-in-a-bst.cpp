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
    struct ChildAndParentNodes {
      TreeNode* parent;
      TreeNode* child;

      bool isLeftChild;
    };

    ChildAndParentNodes findSmallerChild(TreeNode* root) {
      if (root->left == nullptr) {
        return { root, nullptr, true };
      }

      TreeNode* parent = root;
      TreeNode* child = root->left;
      bool isLeftChild = true;

      while (child->right != nullptr) {
        parent = child;
        child = child->right;
        isLeftChild = false;
      }

      return { parent, child, isLeftChild };
    }

    ChildAndParentNodes findLargerChild(TreeNode* root) {
      if (root->right == nullptr) {
        return { root, nullptr, true };
      }

      TreeNode* parent = root;
      TreeNode* child = root->right;
      bool isLeftChild = false;

      while (child->left != nullptr) {
        parent = child;
        child = child->left;
        isLeftChild = true;
      }

      return { parent, child, isLeftChild };
    }


  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (root == nullptr) {
        return nullptr;
      }

      TreeNode* auxiliaryRoot = new TreeNode(root->val, root, root);
      TreeNode* previousNode = auxiliaryRoot;
      TreeNode* currentNode = root;
      bool isLeftChild = true;

      while (currentNode != nullptr) {
        if (currentNode->val == key) {
          if (currentNode->left != nullptr) {
            ChildAndParentNodes smallerChild = findSmallerChild(currentNode);
            swap(currentNode->val, smallerChild.child->val);

            previousNode = smallerChild.parent;
            currentNode = smallerChild.child;
            isLeftChild = smallerChild.isLeftChild;
          } else if (currentNode->right != nullptr) {
            ChildAndParentNodes largerChild = findLargerChild(currentNode);
            swap(currentNode->val, largerChild.child->val);

            previousNode = largerChild.parent;
            currentNode = largerChild.child;
            isLeftChild = largerChild.isLeftChild;
          } else if (isLeftChild) {
            delete currentNode;

            currentNode = nullptr;
            previousNode->left = nullptr;
          } else {
            delete currentNode;

            currentNode = nullptr;
            previousNode->right = nullptr;
          }
        } else if (currentNode->val < key) {
          previousNode = currentNode;
          currentNode = currentNode->right;

          isLeftChild = false;
        } else {
          previousNode = currentNode;
          currentNode = currentNode->left;

          isLeftChild = true;
        }
      }

      TreeNode* newRoot = auxiliaryRoot->left;
      auxiliaryRoot->left = nullptr;
      auxiliaryRoot->right = nullptr;
      delete auxiliaryRoot;

      return newRoot;
    }
};
