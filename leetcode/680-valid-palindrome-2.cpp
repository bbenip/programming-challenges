class Solution {
  private:
    bool validPalindromeWithoutDeletion(
      const string& s,
      int startIndex,
      int endIndex
    ) {

      while (startIndex < endIndex) {
        const char currentCharacter = s[startIndex];
        const char complementaryCharacter = s[endIndex];

        if (currentCharacter != complementaryCharacter) {
          return false;
        }

        startIndex += 1;
        endIndex -= 1;
      }

      return true;
    }

  public:
    bool validPalindrome(string s) {
      int startIndex = 0;
      int endIndex = s.size() - 1;

      while (startIndex < endIndex) {
        const char currentCharacter = s[startIndex];
        const char complementaryCharacter = s[endIndex];

        if (currentCharacter != complementaryCharacter) {
          return (
            validPalindromeWithoutDeletion(s, startIndex + 1, endIndex)
            || validPalindromeWithoutDeletion(s, startIndex, endIndex - 1)
          );
        }

        startIndex += 1;
        endIndex -= 1;
      }

      return true;
    }
};
