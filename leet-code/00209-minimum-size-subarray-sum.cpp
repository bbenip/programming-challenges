class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int minimumSizeOfValidSubArray = nums.size() + 1;

      int startIndex = 0;
      int endIndex = 0;

      int subArraySum = 0;

      while (endIndex < nums.size()) {
        const int lastNumber = nums[endIndex];
        subArraySum += lastNumber;

        while (subArraySum >= target) {
          const int subArraySize = endIndex - startIndex + 1;

          minimumSizeOfValidSubArray = min(
            minimumSizeOfValidSubArray,
            subArraySize
          );

          const int firstNumber = nums[startIndex];
          subArraySum -= firstNumber;

          startIndex += 1;
        }

        endIndex += 1;
      }

      if (minimumSizeOfValidSubArray == nums.size() + 1) {
        return 0;
      }

      return minimumSizeOfValidSubArray;
    }
};
