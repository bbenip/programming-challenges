class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int> characterFrequency;

      for (const char& character : magazine) {
        characterFrequency[character] += 1;
      }

      for (const char& character : ransomNote) {
        int& numberOfCharacters = characterFrequency[character];
        const bool isCharacterAvailable = numberOfCharacters > 0;

        if (!isCharacterAvailable) {
          return false;
        }

        numberOfCharacters -= 1;
      }

      return true;
    }
};
