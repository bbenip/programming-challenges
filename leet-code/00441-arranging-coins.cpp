class Solution {
  public:
    int arrangeCoins(int n) {
      int level = 1;

      while (n >= level) {
        n -= level;
        level += 1;
      }

      return level - 1;
    }
};
