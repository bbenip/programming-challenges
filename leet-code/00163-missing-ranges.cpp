class Solution {
  public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
      if (nums.empty()) {
        return { { lower, upper } };
      }

      vector<vector<int>> ranges;

      for (const auto& num : nums) {
        if (lower < num) {
          vector<int> range = { lower, num - 1 };
          ranges.push_back(range);
        }

        lower = num + 1;
      }

      const int maximumNumber = nums.back();

      if (maximumNumber < upper) {
        vector<int> range = { maximumNumber + 1, upper };
        ranges.push_back(range);
      }

      return ranges;
    }
};
