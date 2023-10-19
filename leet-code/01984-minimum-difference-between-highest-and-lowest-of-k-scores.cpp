class Solution {
  public:
    int minimumDifference(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());

      int minimumDifference = INT_MAX;

      for (int i = k; i <= nums.size(); ++i) {
        const int lowScore = nums[i - k];
        const int highScore = nums[i - 1];

        const int difference = highScore - lowScore;

        minimumDifference = min(minimumDifference, difference);
      }

      return minimumDifference;
    }
};
