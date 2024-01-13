class Solution {
  public:
    int rob(vector<int>& nums) {
      if (nums.size() == 1) {
        return nums.front();
      }

      int maxPreviousPreviousRobAmount1 = 0;
      int maxPreviousRobAmount1 = 0;

      for (int i = 0; i < nums.size() - 1; ++i) {
        const int maxCurrentRobAmount = max(
          maxPreviousPreviousRobAmount1 + nums[i],
          maxPreviousRobAmount1
        );

        maxPreviousPreviousRobAmount1 = maxPreviousRobAmount1;
        maxPreviousRobAmount1 = maxCurrentRobAmount;
      }

      int maxPreviousPreviousRobAmount2 = 0;
      int maxPreviousRobAmount2 = 0;

      for (int i = nums.size() - 1; i > 0; --i) {
        const int maxCurrentRobAmount = max(
          maxPreviousPreviousRobAmount2 + nums[i],
          maxPreviousRobAmount2
        );

        maxPreviousPreviousRobAmount2 = maxPreviousRobAmount2;
        maxPreviousRobAmount2 = maxCurrentRobAmount;
      }

      int maxRobAmount = max(
        maxPreviousRobAmount1,
        maxPreviousRobAmount2
      );

      return maxRobAmount;
    }
};
