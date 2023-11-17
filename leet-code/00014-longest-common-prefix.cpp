class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      string prefix = "";

      const int firstStringSize = strs[0].size();

      for (int i = 0; i < firstStringSize; ++i) {
        const char firstStringCharacter = strs[0][i];

        for (const auto& str : strs) {
          if (i >= str.size() || str[i] != firstStringCharacter) {
            return prefix;
          }
        }

        prefix += firstStringCharacter;
      }

      return prefix;
    }
};
