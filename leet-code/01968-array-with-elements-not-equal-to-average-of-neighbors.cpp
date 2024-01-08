class Solution {
  public:
    vector<int> rearrangeArray(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      vector<int> result;

      for (int i = 0; i < nums.size(); ++i) {
        const bool isEvenIteration = i % 2 == 0;

        if (isEvenIteration) {
          result.push_back(nums[i / 2]);
        } else {
          result.push_back(nums[nums.size() - 1  - i / 2]);
        }
      }

      return result;
    }
};
