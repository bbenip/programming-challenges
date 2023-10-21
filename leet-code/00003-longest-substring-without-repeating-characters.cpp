class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int maximumLengthOfSubstring = 0;
      int currentLengthOfSubstring = 0;

      int substringStartIndex = 0;

      unordered_map<char, int> characterToIndex;

      for (int i = 0; i < s.size(); ++i) {
        const char currentCharacter = s[i];

        if (!characterToIndex.contains(currentCharacter)) {
          characterToIndex[currentCharacter] = i;
          currentLengthOfSubstring += 1;

          maximumLengthOfSubstring = max(
            maximumLengthOfSubstring,
            currentLengthOfSubstring
          );
        } else {
          const int indexOfPreviousOccurrence = (
            characterToIndex[currentCharacter]
          );

          while (substringStartIndex <= indexOfPreviousOccurrence) {
            characterToIndex.erase(s[substringStartIndex]);
            substringStartIndex += 1;
          }

          currentLengthOfSubstring = i - substringStartIndex + 1;
          characterToIndex[currentCharacter] = i;
        }
      }

      return maximumLengthOfSubstring;
    }
};
