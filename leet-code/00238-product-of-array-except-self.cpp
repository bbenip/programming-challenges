class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> output(nums.size(), 1);

      int productFromStart = 1;

      for (int i = 0; i < nums.size(); ++i) {
        output[i] *= productFromStart;
        productFromStart *= nums[i];
      }

      int productFromEnd = 1;

      for (int i = nums.size() - 1; i >= 0; --i) {
        output[i] *= productFromEnd;
        productFromEnd *= nums[i];
      }

      return output;
    }
};
