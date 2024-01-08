class Solution {
  public:
    vector<int> rearrangeArray(vector<int>& nums) {
      for (int i = 1; i < nums.size() - 1; ++i) {
        const int& previousNumber = nums[i - 1];
        int& currentNumber = nums[i];
        int& nextNumber = nums[i + 1];

        const bool isIncreasing = (
          previousNumber < currentNumber
          && currentNumber < nextNumber
        );

        const bool isDecreasing = (
          previousNumber > currentNumber
          && currentNumber > nextNumber
        );

        if (isIncreasing || isDecreasing) {
          swap(currentNumber, nextNumber);
        }
      }

      return nums;
    }
};
