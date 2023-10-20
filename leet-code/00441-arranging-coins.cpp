class Solution {
  public:
    int arrangeCoins(int n) {
      // These bounds are based on their respective triangle numbers
      // The nth triangle number is the sum of all integers from 1 to n
      // T_1 is 1
      // T_65536 is the smallest triangle number greater than 2^31
      int numRowsLowerBound = 1;
      int numRowsUpperBound = 65536;

      // The lower bound is always less than the upper bound in this loop
      // So, the triangle number calculated is less than T_65536
      // As a result, no overflow should occur
      while (numRowsLowerBound < numRowsUpperBound) {
        // Calculate midpoint between bounds without overflow
        const int numRows = (
          numRowsLowerBound + (numRowsUpperBound - numRowsLowerBound) / 2
        );

        // Calculate the triangle number without overflow
        const bool isNumRowsEven = numRows % 2 == 0;
        const int factor1 = isNumRowsEven ? numRows / 2: numRows;
        const int factor2 = isNumRowsEven ? numRows + 1 : (numRows + 1) / 2;

        const int numberOfCoinsRequired = factor1 * factor2;

        if (numberOfCoinsRequired > n) {
          numRowsUpperBound = numRows;
        } else {
          numRowsLowerBound = numRows + 1;
        }
      }

      return numRowsUpperBound - 1;
    }
};
