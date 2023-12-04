class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      int candidate = 0;
      int frequency = 0;

      for (const auto& num : nums) {
        if (frequency == 0) {
          candidate = num;
        }

        if (num == candidate) {
          frequency += 1;
        } else {
          frequency -= 1;
        }
      }

      return candidate;
    }
};
