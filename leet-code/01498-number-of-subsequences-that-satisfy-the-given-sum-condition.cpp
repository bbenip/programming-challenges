class Solution {
  private:
    int exponentiationWithModulo(
      const int inputBase,
      const int inputExponent,
      const int modulo
    ) {
      // Use exponentiation by squaring method
      long long base = inputBase;
      int exponent = inputExponent;

      long long result = 1;

      while (exponent > 0) {
        const bool isExponentOdd = exponent % 2 != 0;

        if (isExponentOdd) {
          result *= base;
          result %= modulo;
        }

        base *= base;
        base %= modulo;

        exponent /= 2;
      }

      return ((int) result);
    }

  public:
    int numSubseq(vector<int>& nums, int target) {
      const int MODULO_VALUE = 1E9 + 7;

      sort(nums.begin(), nums.end());

      int numberOfValidSubsequences = 0;

      int index1 = 0;
      int index2 = nums.size() - 1;

      while (index1 <= index2) {
        const int smallestNumber = nums[index1];
        const int largestNumber = nums[index2];

        const int sum = smallestNumber + largestNumber;

        if (sum > target) {
          index2 -= 1;
          continue;
        }

        const int indexDifference = index2 - index1;

        const int numberOfSubsequencesStartingAtIndex1 = (
          exponentiationWithModulo(2, indexDifference, MODULO_VALUE)
        );

        numberOfValidSubsequences += numberOfSubsequencesStartingAtIndex1;
        numberOfValidSubsequences %= MODULO_VALUE;

        index1 += 1;
      }

      return numberOfValidSubsequences;
    }
};
