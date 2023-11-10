class Solution {
  public:
    int minFlips(string s) {
      int startIndex = 0;
      int endIndex = 0;

      int minimumNumberOfFlips = s.size();

      char firstCharacterInFlips1 = '0';
      int numberOfFlips1 = 0;

      char firstCharacterInFlips2 = '1';
      int numberOfFlips2 = 0;

      while (endIndex < s.size() * 2) {
        const char firstCharacter = s[startIndex % s.size()];
        const char lastCharacter = s[endIndex % s.size()];

        int substringSize = endIndex - startIndex + 1;

        const char lastCharacterInFlips1 = (
          (firstCharacterInFlips1 == '0' ^ substringSize % 2 == 0) ? '0' : '1'
        );

        const char lastCharacterInFlips2 = (
          (lastCharacterInFlips1 == '0') ? '1' : '0'
        );

        if (lastCharacter != lastCharacterInFlips1) {
          numberOfFlips1 += 1;
        }

        if (lastCharacter != lastCharacterInFlips2) {
          numberOfFlips2 += 1;
        }

        if (substringSize > s.size()) {
          if (firstCharacter != firstCharacterInFlips1) {
            numberOfFlips1 -= 1;
          }

          if (firstCharacter != firstCharacterInFlips2) {
            numberOfFlips2 -= 1;
          }

          swap(firstCharacterInFlips1, firstCharacterInFlips2);

          startIndex += 1;
          substringSize -= 1;
        }

        if (substringSize == s.size()) {
          minimumNumberOfFlips = min(
            minimumNumberOfFlips,
            min(numberOfFlips1, numberOfFlips2)
          );
        }

        endIndex += 1;
      }

      return minimumNumberOfFlips;
    }
};
