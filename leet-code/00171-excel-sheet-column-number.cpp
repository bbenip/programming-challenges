class Solution {
  public:
    int titleToNumber(string columnTitle) {
      const int radix = 'Z' - 'A' + 1;

      int number = 0;

      for (const auto& numeral : columnTitle) {
        const int numericalValue = numeral - 'A' + 1;

        number *= radix;
        number += numericalValue;
      }

      return number;
    }
};
