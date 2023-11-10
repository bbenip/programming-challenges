class Solution {
  public:
    int minFlips(string s) {
      int startIndex = 0;
      int endIndex = 0;

      int minimumNumberOfFlips = s.size();

      int numberOfFlips = 0;

      while (endIndex < s.size() * 2) {
        const char firstCharacter = s[startIndex % s.size()];
        const char lastCharacter = s[endIndex % s.size()];

        const char expectedLastCharacter = endIndex % 2 == 0 ? '0' : '1';

        if (lastCharacter != expectedLastCharacter) {
          numberOfFlips += 1;
        }

        int substringSize = endIndex - startIndex + 1;

        if (substringSize > s.size()) {
          const char expectedFirstCharacter = startIndex % 2 == 0 ? '0' : '1';
          if (firstCharacter != expectedFirstCharacter) {
            numberOfFlips -= 1;
          }

          startIndex += 1;
          substringSize -= 1;
        }

        if (substringSize == s.size()) {
          minimumNumberOfFlips = min(
            minimumNumberOfFlips,
            min(numberOfFlips, substringSize - numberOfFlips)
          );
        }

        endIndex += 1;
      }

      return minimumNumberOfFlips;
    }
};
