class Solution {
  public:
    int minOperations(vector<int>& nums, int k) {
      int minimumNumberOfOperations = nums.size() + 1;

      int total = 0;

      for (const auto& num : nums) {
        total += num;
      }

      const int target = total - k;

      int startIndex = 0;
      int endIndex = 0;

      int sum = 0;

      while (endIndex < nums.size()) {
        sum += nums[endIndex];

        while (startIndex <= endIndex && sum > target) {
          sum -= nums[startIndex];
          startIndex += 1;
        }

        if (sum == target) {
          minimumNumberOfOperations = min(
            minimumNumberOfOperations,
            ((int) nums.size()) - (endIndex - startIndex + 1)
          );
        }

        endIndex += 1;
      }

      if (minimumNumberOfOperations == nums.size() + 1) {
        return -1;
      }

      return minimumNumberOfOperations;
    }
};
