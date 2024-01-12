class Solution {
  public:
    int rob(vector<int>& nums) {
      if (nums.size() == 1) {
        return nums.front();
      }

      int maxPreviousPreviousRobAmount = nums[0];
      int maxPreviousRobAmount = max(nums[0], nums[1]);

      for (int i = 2; i < nums.size(); ++i) {
        const int maxCurrentRobAmount = max(
          maxPreviousPreviousRobAmount + nums[i],
          maxPreviousRobAmount
        );

        maxPreviousPreviousRobAmount = maxPreviousRobAmount;
        maxPreviousRobAmount = maxCurrentRobAmount;
      }

      const int maxRobAmount = max(
        maxPreviousPreviousRobAmount,
        maxPreviousRobAmount
      );

      return maxRobAmount;
    }
};
