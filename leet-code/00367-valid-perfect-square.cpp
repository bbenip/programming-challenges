class Solution {
  public:
    bool isPerfectSquare(int num) {
      // The largest whole square root for a 32-bit integer is 46340
      int lowerBound = 0;
      int upperBound = 46340;

      while (lowerBound <= upperBound) {
        // Calculate midpoint between bounds without overflow
        const int candidate = lowerBound + (upperBound - lowerBound) / 2;
        const int squaredValue = candidate * candidate;

        if (squaredValue == num) {
          return true;
        } else if (squaredValue < num) {
          lowerBound = candidate + 1;
        } else if (squaredValue > num) {
          upperBound = candidate - 1;
        }
      }

      return false;
    }
};
