class Solution {
  public:
    int rob(vector<int>& nums) {
      int maxPreviousPreviousRobAmount = 0;
      int maxPreviousRobAmount = 0;

      for (const auto& num : nums) {
        const int maxCurrentRobAmount = max(
          maxPreviousPreviousRobAmount + num,
          maxPreviousRobAmount
        );

        maxPreviousPreviousRobAmount = maxPreviousRobAmount;
        maxPreviousRobAmount = maxCurrentRobAmount;
      }

      return maxPreviousRobAmount;
    }
};
