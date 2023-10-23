class Solution {
  public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> squaredNums;

      // Find first non-negative number
      int lowerBound = 0;
      int upperBound = nums.size();

      while (lowerBound < upperBound) {
        // Calculate midpoint index without overflow
        const int candidateIndex = lowerBound + (upperBound - lowerBound) / 2;
        const int candidate = nums[candidateIndex];

        if (candidate < 0) {
          lowerBound = candidateIndex + 1;
        } else {
          upperBound = candidateIndex;
        }
      }

      // Sort negative numbers in ascending order of absolute value
      reverse(nums.begin(), nums.begin() + lowerBound);

      // Collate negative and non-negative numbers based on absolute value
      int negativeSubarrayIndex = 0;
      int nonNegativeSubarrayIndex = lowerBound;

      while (
        negativeSubarrayIndex < lowerBound
        && nonNegativeSubarrayIndex < nums.size()
      ) {
        const int negativeValue = nums[negativeSubarrayIndex];
        const int nonNegativeValue = nums[nonNegativeSubarrayIndex];

        if (abs(negativeValue) < nonNegativeValue) {
          squaredNums.push_back(negativeValue);
          negativeSubarrayIndex += 1;
        } else {
          squaredNums.push_back(nonNegativeValue);
          nonNegativeSubarrayIndex += 1;
        }
      }

      // Insert remaining portion of subarrays
      squaredNums.insert(
        squaredNums.end(),
        nums.begin() + negativeSubarrayIndex,
        nums.begin() + lowerBound
      );

      squaredNums.insert(
        squaredNums.end(),
        nums.begin() + nonNegativeSubarrayIndex,
        nums.end()
      );

      // Square every element, now in the correct order
      for (auto& num : squaredNums) {
        num *= num;
      }

      return squaredNums;
    }
};
