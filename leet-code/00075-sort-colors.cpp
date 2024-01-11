class Solution {
  public:
    void sortColors(vector<int>& nums) {
      vector<int> colors(3, 0);

      for (const auto& num : nums) {
        colors[num] += 1;
      }

      int index = 0;

      for (int i = 0; i < colors.size(); ++i) {
        const int count = colors[i];

        for (int j = 0; j < count; ++j) {
          nums[index] = i;
          index += 1;
        }
      }
    }
};
