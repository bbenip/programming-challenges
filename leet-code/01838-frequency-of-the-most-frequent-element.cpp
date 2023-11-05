class Solution {
  public:
    int maxFrequency(vector<int>& nums, int k) {
      if (nums.size() == 0) {
        return 0;
      }

      sort(nums.begin(), nums.end());

      int maxFrequencySoFar = 1;
      vector<long long> sumOfPreceedingElements = { nums[0] };

      for (int i = 1; i < nums.size(); ++i) {
        sumOfPreceedingElements.push_back(
          sumOfPreceedingElements[i - 1] + nums[i]
        );

        int candidateIndex = i - maxFrequencySoFar;

        long long candidateSum = (
          sumOfPreceedingElements[i]
          - sumOfPreceedingElements[candidateIndex]
          + nums[candidateIndex]
        );

        long long maxSum = ((long long) (maxFrequencySoFar + 1)) * nums[i];

        while (maxSum - candidateSum <= k) {
          maxFrequencySoFar += 1;

          candidateIndex = i - maxFrequencySoFar;

          if (candidateIndex < 0 ) {
            break;
          }

          candidateSum += nums[candidateIndex];
          maxSum += nums[i];
        }
      }

      return maxFrequencySoFar;
    }
};
