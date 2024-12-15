class Solution {
  public:
    int findPairs(vector<int>& nums, int k) {
      unordered_map<int, int> numberFrequency;

      for (const auto& num : nums) {
        numberFrequency[num] += 1;
      }

      int totalKDiffPairs = 0;

      for (const auto& [number, frequency] : numberFrequency) {
        if (k == 0) {
          if (frequency > 1) {
            totalKDiffPairs += 1;
          }
        } else {
          const int kComplement = number + k;

          if (numberFrequency.contains(kComplement)) {
            totalKDiffPairs += 1;
          }
        }
      }

      return totalKDiffPairs;
    }
};
