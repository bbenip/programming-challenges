class Solution {
  public:
    void reverseString(vector<char>& s) {
      const int midpointIndex = s.size() / 2;

      for (int i = 0; i < midpointIndex; ++i) {
        swap(s[i], s[s.size() - i - 1]);
      }
    }
};
