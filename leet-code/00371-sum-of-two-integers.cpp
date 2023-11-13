class Solution {
  public:
    int getSum(int a, int b) {
      const int numberOfBitsInInteger = 32;

      int result = 0;

      int index = 0;
      int carry = 0;

      while (
        (a != 0 || b != 0 || carry != 0)
        && index < numberOfBitsInInteger
      ) {
        const int bitFromA = a & 1;
        const int bitFromB = b & 1;

        const int bit = bitFromA ^ bitFromB ^ carry;
        result |= (bit << index);

        a >>= 1;
        b >>= 1;

        carry = (
          (bitFromA & bitFromB)
          | (bitFromA & carry)
          | (bitFromB & carry)
        );

        int addend = 1;

        while (index & addend) {
          index ^= addend;
          addend <<= 1;
        }

        index ^= addend;
      }

      return result;
    }
};
