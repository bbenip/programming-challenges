class Solution {
  public:
    int numberOfSteps(int num) {
      int stepCount = 0;

      while (num != 0) {
        const bool isEven = num % 2 == 0;

        if (isEven) {
          num /= 2;
        } else {
          num -= 1;
        }

        stepCount += 1;
      }

      return stepCount;
    }
};
