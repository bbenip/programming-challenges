class Solution {
  public:
    string minWindow(string s, string t) {
      unordered_map<char, int> tCharacterFrequency;

      for (const auto& ch : t) {
        tCharacterFrequency[ch] += 1;
      }

      int minimumWindowSize = s.size() + 1;
      int minimumStartIndex = -1;

      int startIndex = 0;
      int endIndex = 0;

      int numDifferencesWithT = t.size();

      unordered_map<char, int> sCharacterFrequency;

      while (endIndex < s.size()) {
        const char lastCharacter = s[endIndex];
        sCharacterFrequency[lastCharacter] += 1;

        if (
          tCharacterFrequency.contains(lastCharacter)
          && (
            tCharacterFrequency[lastCharacter] >=
            sCharacterFrequency[lastCharacter]
          )
        ) {
          numDifferencesWithT -= 1;
        }

        char firstCharacter = s[startIndex];

        while (
          startIndex <= endIndex
          && (
            !tCharacterFrequency.contains(firstCharacter)
            || (
              sCharacterFrequency[firstCharacter] >
              tCharacterFrequency[firstCharacter]
            )
          )
        ) {
          sCharacterFrequency[firstCharacter] -= 1;
          startIndex += 1;
          firstCharacter = s[startIndex];
        }

        const bool isWindowContainingT = (numDifferencesWithT == 0);
        const int currentWindowSize = endIndex - startIndex + 1;

        if (isWindowContainingT && currentWindowSize < minimumWindowSize) {
          minimumWindowSize = currentWindowSize;
          minimumStartIndex = startIndex;
        }

        endIndex += 1;
      }

      if (minimumWindowSize > s.size()) {
        return "";
      }

      return s.substr(
        minimumStartIndex,
        minimumWindowSize
      );
    }
};
