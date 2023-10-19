class Solution {
  public:
    vector<int> countBits(int n) {
      vector<int> numberOf1Bits = { 0 };

      for (unsigned int i = 1; i <= n; ++i) {
        const int allButLastBit = i >> 1;
        const int numberOf1sInAllButLastBit = numberOf1Bits[allButLastBit];
        const int numberOf1sInLastBit = i & 1;

        const int numberOf1BitsInI = (
          numberOf1sInAllButLastBit + numberOf1sInLastBit
        );

        numberOf1Bits.push_back(numberOf1BitsInI);
      }

      return numberOf1Bits;
    }
};
