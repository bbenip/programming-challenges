class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> numbersAndFrequencies;

      for (const auto& num : nums) {
        numbersAndFrequencies[num] += 1;
      }

      vector<vector<int>> numbersAtFrequency(nums.size() + 1);

      for (const auto& [number, frequency] : numbersAndFrequencies) {
        numbersAtFrequency[frequency].push_back(number);
      }

      vector<int> topKFrequentElements;

      for (int i = nums.size(); i >= 0; --i) {
        const auto& numbersWithFrequencyI = numbersAtFrequency[i];

        for (const auto& number : numbersWithFrequencyI) {
          topKFrequentElements.push_back(number);

          if (topKFrequentElements.size() == k) {
            return topKFrequentElements;
          }
        }
      }

      return {};
    }
};
