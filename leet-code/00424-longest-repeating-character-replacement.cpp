class Solution {
  public:
    int characterReplacement(string s, int k) {
      const int ALPHABET_SIZE = 26;
      vector<int> characterFrequency(ALPHABET_SIZE, 0);

      int maxLengthOfViableSubstring = 0;
      int maxFrequencyInViableSubstring = 0;

      int substringStartIndex = 0;
      int substringEndIndex = 0;

      while (substringEndIndex < s.size()) {
        const char newCharacter = s[substringEndIndex];
        characterFrequency[newCharacter - 'A'] += 1;

        maxFrequencyInViableSubstring = max(
          maxFrequencyInViableSubstring,
          characterFrequency[newCharacter - 'A']
        );

        const int substringSize = substringEndIndex - substringStartIndex + 1;
        const int minReplacementsRequired = (
          substringSize - maxFrequencyInViableSubstring
        );

        if (minReplacementsRequired > k) {
          const char firstCharacter = s[substringStartIndex];
          characterFrequency[firstCharacter - 'A'] -= 1;

          substringStartIndex += 1;
        } else {
          maxLengthOfViableSubstring += 1;
        }

        substringEndIndex += 1;
      }

      return maxLengthOfViableSubstring;
    }
};
