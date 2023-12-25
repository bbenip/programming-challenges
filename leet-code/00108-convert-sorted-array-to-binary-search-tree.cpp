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
    TreeNode* sortedArrayToBST(
      const vector<int>& nums,
      const int index1,
      const int index2
    ) {
      if (index1 >= index2) {
        return nullptr;
      }

      const int rootIndex = index1 + (index2 - index1) / 2;
      const int rootValue = nums[rootIndex];

      TreeNode* root = new TreeNode(
        rootValue,
        sortedArrayToBST(nums, index1, rootIndex),
        sortedArrayToBST(nums, rootIndex + 1, index2)
      );

      return root;
    }

  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return sortedArrayToBST(nums, 0, nums.size());
    }
};
