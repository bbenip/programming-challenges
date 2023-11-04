class Solution {
  public:
    int mySqrt(int x) {
      // The largest whole square root of a non-negative 32-bit integer is 46340
      int lowerBound = 0;
      int upperBound = 46341;

      while (lowerBound < upperBound) {
        // Calculate midpoint without overflow
        const int candidate = lowerBound + (upperBound - lowerBound) / 2;
        const int squaredValue = candidate * candidate;

        if (squaredValue == x) {
          return candidate;
        } else if (squaredValue < x) {
          lowerBound = candidate + 1;
        } else if (squaredValue > x) {
          upperBound = candidate;
        }
      }

      return upperBound - 1;
    }
};
