class Solution {
  public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
      reverse(num.begin(), num.end());

      int index = 0;
      int carry = 0;

      while (k > 0 || carry > 0) {
        const int digitFromK = k % 10;
        const int addend = digitFromK + carry;

        if (index < num.size()) {
          num[index] += addend;
        } else {
          num.push_back(addend);
        }

        carry = num[index] / 10;
        num[index] %= 10;

        index += 1;
        k /= 10;
      }

      reverse(num.begin(), num.end());

      return num;
    }
};
