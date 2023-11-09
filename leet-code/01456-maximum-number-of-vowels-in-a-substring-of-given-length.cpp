class Solution {
  public:
    int maxVowels(string s, int k) {
      int startIndex = 0;
      int endIndex = 0;

      const string vowels = "aeiou";

      int maxNumberOfVowels = 0;
      int currentNumberOfVowels = 0;

      while (endIndex < s.size()) {
        const int substringSize = endIndex - startIndex + 1;

        if (substringSize > k) {
          const char firstCharacter = s[startIndex];
          const bool isFirstCharacterAVowel = (
            vowels.find(firstCharacter) != string::npos
          );

          if (isFirstCharacterAVowel) {
            currentNumberOfVowels -= 1;
          }

          startIndex += 1;
        }

        const char lastCharacter = s[endIndex];
        const bool isLastCharacterAVowel = (
          vowels.find(lastCharacter) != string::npos
        );

        if (isLastCharacterAVowel) {
          currentNumberOfVowels += 1;
        }

        maxNumberOfVowels = max(maxNumberOfVowels, currentNumberOfVowels);

        endIndex += 1;
      }

      return maxNumberOfVowels;
    }
};
