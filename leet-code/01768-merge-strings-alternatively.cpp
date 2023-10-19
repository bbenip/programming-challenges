class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
      string mergedWord = "";

      int word1Index = 0;
      int word2Index = 0;

      while (
        word1Index < word1.size()
        && word2Index < word2.size()
      ) {
        mergedWord += word1[word1Index];
        mergedWord += word2[word2Index];

        word1Index += 1;
        word2Index += 1;
      }

      if (word1Index < word1.size()) {
        const int numRemainingCharacters = word1.size() - word1Index;
        mergedWord += word1.substr(word1Index, numRemainingCharacters);
      }

      if (word2Index < word2.size()) {
        const int numRemainingCharacters = word2.size() - word2Index;
        mergedWord += word2.substr(word2Index, numRemainingCharacters);
      }

      return mergedWord;
    }
};
