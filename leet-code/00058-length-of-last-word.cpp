class Solution {
  public:
    int lengthOfLastWord(string s) {
      int lastWordEndIndex = s.size() - 1;

      while (lastWordEndIndex >= 0 && s[lastWordEndIndex] == ' ') {
        lastWordEndIndex -= 1;
      }

      int lastWordStartIndex = lastWordEndIndex;

      while (lastWordStartIndex >= 0 && s[lastWordStartIndex] != ' ') {
        lastWordStartIndex -= 1;
      }

      const int lengthOfLastWord = lastWordEndIndex - lastWordStartIndex;

      return lengthOfLastWord;
    }
};
