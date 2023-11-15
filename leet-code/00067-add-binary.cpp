class Solution {
  public:
    string addBinary(string a, string b) {
      string sum = "";

      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());

      int indexForA = 0;
      int indexForB = 0;
      int carry = 0;

      while (indexForA < a.size() || indexForB < b.size() || carry > 0) {
        int bitFromA = 0;
        int bitFromB = 0;

        if (indexForA < a.size()) {
          bitFromA = a[indexForA] - '0';
          indexForA += 1;
        }

        if (indexForB < b.size()) {
          bitFromB = b[indexForB] - '0';
          indexForB += 1;
        }

        const int currentBit = (bitFromA + bitFromB + carry) % 2;
        carry = (bitFromA + bitFromB + carry) / 2;

        sum += currentBit + '0';
      }

      reverse(sum.begin(), sum.end());

      return sum;
    }
};
