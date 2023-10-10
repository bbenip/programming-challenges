class Solution {
  public:
    bool isPalindrome(string s) {
      string simplifiedString = "";

      for (const auto& character : s) {
        const char newCharacter = tolower(character);

        if (isalnum(newCharacter)) {
          simplifiedString += newCharacter;
        }
      }

      const int midPoint = simplifiedString.size() / 2;

      for (int i = 0; i < midPoint; ++i) {
        const char currentCharacter = simplifiedString[i];
        const char correspondingCharacter = simplifiedString[
          simplifiedString.size() - i - 1
        ];

        if (currentCharacter != correspondingCharacter) {
          return false;
        }
      }

      return true;
    }
};
