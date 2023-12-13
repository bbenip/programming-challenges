class Solution {
  public:
    int climbStairs(int n) {
      int waysToClimbToPreviousStep = 1;
      int waysToClimbToCurrentStep = 1;

      for (int i = 2; i <= n; ++i) {
        const int waysToClimbToNextStep = (
          waysToClimbToPreviousStep + waysToClimbToCurrentStep
        );

        waysToClimbToPreviousStep = waysToClimbToCurrentStep;
        waysToClimbToCurrentStep = waysToClimbToNextStep;
      }

      return waysToClimbToCurrentStep;
    }
};
