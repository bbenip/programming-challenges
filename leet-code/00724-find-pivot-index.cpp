class Solution {
  public:
    int pivotIndex(vector<int>& nums) {
      int leftSum = 0;
      int inclusiveRightSum = 0;

      for (const auto& num : nums) {
        inclusiveRightSum += num;
      }

      for (int i = 0; i < nums.size(); ++i) {
        const int rightSum = inclusiveRightSum - nums[i];

        if (leftSum == rightSum) {
          return i;
        }

        leftSum += nums[i];
        inclusiveRightSum = rightSum;
      }

      return -1;
    }
};
