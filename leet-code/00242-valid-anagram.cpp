class Solution {
  public:
    bool isAnagram(string s, string t) {
      const int ALPHABET_SIZE = 26;
      vector<int> characterFrequency(ALPHABET_SIZE, 0);

      for (const auto& ch : s) {
        characterFrequency[ch - 'a'] += 1;
      }

      for (const auto& ch : t) {
        characterFrequency[ch - 'a'] -= 1;
      }

      for (const auto& frequency : characterFrequency) {
        if (frequency != 0) {
          return false;
        }
      }

      return true;
    }
};
