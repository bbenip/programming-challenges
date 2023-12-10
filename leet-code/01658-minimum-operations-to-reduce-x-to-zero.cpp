class Solution {
  public:
    int minOperations(vector<int>& nums, int k) {
      int minimumNumberOfOperations = nums.size() + 1;

      int total = 0;

      for (const auto& num : nums) {
        total += num;
      }

      unordered_map<int, int> leftSumToIndex;
      unordered_map<int, int> rightSumToIndex;

      leftSumToIndex[0] = -1;
      rightSumToIndex[0] = nums.size();

      int leftSum = 0;
      int rightSum = 0;

      const int targetInnerSum = total - k;

      for (int i = 0; i < nums.size(); ++i) {
        const int leftIndex = i;
        const int rightIndex = nums.size() - 1 - i;

        leftSum += nums[leftIndex];
        rightSum += nums[rightIndex];

        leftSumToIndex[leftSum] = leftIndex;
        rightSumToIndex[rightSum] = rightIndex;

        const int leftComplement = leftSum - targetInnerSum;
        const int rightComplement = rightSum - targetInnerSum;

        if (leftSumToIndex.contains(leftComplement)) {
          const int indexOfComplement = leftSumToIndex[leftComplement];

          minimumNumberOfOperations = min(
            minimumNumberOfOperations,
            (int) (nums.size()) - (leftIndex - indexOfComplement)
          );
        }

        if (rightSumToIndex.contains(rightComplement)) {
          const int indexOfComplement = rightSumToIndex[rightComplement];

          minimumNumberOfOperations = min(
            minimumNumberOfOperations,
            (int) (nums.size()) - (indexOfComplement - rightIndex)
          );
        }
      }

      if (minimumNumberOfOperations > nums.size()) {
        return -1;
      }

      return minimumNumberOfOperations;
    }
};
