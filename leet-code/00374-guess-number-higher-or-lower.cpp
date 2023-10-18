/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
    int guessNumber(int n) {
      int lowerBound = 1;
      int upperBound = n;

      while (lowerBound <= upperBound) {
        // Calculate midpoint index without overflow
        const int candidate = (lowerBound + (upperBound - lowerBound) / 2);

        const int guessResult = guess(candidate);

        if (guessResult == 0) {
          return candidate;
        } else if (guessResult == -1) {
          upperBound = candidate - 1;
        } else if (guessResult == 1) {
          lowerBound = candidate + 1;
        }
      }

      return -1;
    }
};
