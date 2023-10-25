class Solution {
  public:
    bool isSubsequence(string s, string t) {
      int sIndex = 0;
      int tIndex = 0;

      while (sIndex < s.size() && tIndex < t.size()) {
        const char characterInS = s[sIndex];
        const char characterInT = t[tIndex];

        if (characterInS == characterInT) {
          sIndex += 1;
        }

        tIndex += 1;
      }

      return sIndex == s.size();
    }
};
