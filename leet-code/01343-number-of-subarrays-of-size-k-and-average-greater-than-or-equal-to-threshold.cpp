class Solution {
  public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int numSubarraysAboveThreshold = 0;

      const int thresholdSum = k * threshold;

      int subarraySum = 0;

      for (int i = 0; i < k - 1; ++i) {
        subarraySum += arr[i];
      }

      for (int i = k - 1; i < arr.size(); ++i) {
        if (i >= k) {
          subarraySum -= arr[i - k];
        }

        subarraySum += arr[i];

        if (subarraySum >= thresholdSum) {
          numSubarraysAboveThreshold += 1;
        }
      }

      return numSubarraysAboveThreshold;
    }
};
