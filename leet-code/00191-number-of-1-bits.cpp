class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int numberOf1Bits = 0;

      while (n > 0) {
        bool is1Bit = n & 1;

        if (is1Bit) {
          numberOf1Bits += 1;
        }

        n >>= 1;
      }

      return numberOf1Bits;
    }
};
