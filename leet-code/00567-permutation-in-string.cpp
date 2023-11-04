class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char, int> s1CharacterFrequency;

      for (const auto& ch : s1) {
        s1CharacterFrequency[ch] += 1;
      }

      unordered_map<char, int> substringCharacterFrequency;

      int startIndex = 0;
      int endIndex = 0;

      while (endIndex < s2.size()) {
        const char& currentCharacter = s2[endIndex];
        const int substringSize = endIndex - startIndex + 1;

        substringCharacterFrequency[currentCharacter] += 1;

        if (!s1CharacterFrequency.contains(currentCharacter)) {
          substringCharacterFrequency.clear();
          startIndex = endIndex + 1;
        } else if (
          substringCharacterFrequency[currentCharacter] >
          s1CharacterFrequency[currentCharacter]
        ) {
          char firstCharacter = s2[startIndex];

          while (firstCharacter != currentCharacter) {
            substringCharacterFrequency[firstCharacter] -= 1;
            startIndex += 1;
            firstCharacter = s2[startIndex];
          }

          substringCharacterFrequency[currentCharacter] -= 1;
          startIndex += 1;
        } else if (substringSize == s1.size()) {
          return true;
        }

        endIndex += 1;
      }

      return false;
    }
};
