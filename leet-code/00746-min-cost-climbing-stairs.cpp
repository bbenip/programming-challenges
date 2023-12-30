class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
      int minCostPreviousPreviousStep = 0;
      int minCostPreviousStep = 0;

      for (int i = 2; i <= cost.size(); ++i) {
        const int minCostCurrentStep = min(
          minCostPreviousPreviousStep + cost[i - 2],
          minCostPreviousStep + cost[i - 1]
        );

        minCostPreviousPreviousStep = minCostPreviousStep;
        minCostPreviousStep = minCostCurrentStep;
      }

      return minCostPreviousStep;
    }
};
