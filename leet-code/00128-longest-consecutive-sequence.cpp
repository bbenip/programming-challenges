class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      int longestConsecutiveRange = 0;

      unordered_map<int, int> ranges;

      for (const auto& num : nums) {
        if (ranges.contains(num)) {
          continue;
        }

        const int numberMinus1 = num - 1;
        const int numberPlus1 = num + 1;

        const bool isInSmallerRange = (
          ranges.contains(numberMinus1)
          && ranges[numberMinus1] < num
        );

        const bool isInLargerRange = (
          ranges.contains(numberPlus1)
          && ranges[numberPlus1] > num
        );

        const bool isCombiningRanges = (
          isInSmallerRange && isInLargerRange
        );

        if (isCombiningRanges) {
          const int smallestValue = ranges[numberMinus1];
          const int largestValue = ranges[numberPlus1];

          ranges.erase(numberMinus1);
          ranges.erase(numberPlus1);

          ranges[smallestValue] = largestValue;
          ranges[largestValue] = smallestValue;

          longestConsecutiveRange = max(
            longestConsecutiveRange,
            largestValue - smallestValue + 1
          );
        } else if (isInSmallerRange) {
          const int smallestValue = ranges[numberMinus1];

          ranges.erase(numberMinus1);

          ranges[smallestValue] = num;
          ranges[num] = smallestValue;

          longestConsecutiveRange = max(
            longestConsecutiveRange,
            num - smallestValue + 1
          );
        } else if (isInLargerRange) {
          const int largestValue = ranges[numberPlus1];

          ranges.erase(numberPlus1);

          ranges[largestValue] = num;
          ranges[num] = largestValue;

          longestConsecutiveRange = max(
            longestConsecutiveRange,
            largestValue - num + 1
          );
        } else {
          ranges[num] = num;
          longestConsecutiveRange = max(longestConsecutiveRange, 1);
        }
      }

      return longestConsecutiveRange;
    }
};
