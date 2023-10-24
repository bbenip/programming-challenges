class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      const int n = nums.size();

      // The nth triangle number is the sum of all integers from 1 to n
      // Since n is at most 10^4, there is no overflow
      int nthTriangleNumber = (n * (n + 1)) / 2;

      int sum = 0;

      for (const auto& num : nums) {
        sum += num;
      }

      return nthTriangleNumber - sum;
    }
};
