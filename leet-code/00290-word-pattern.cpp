class Solution {
  private:
    vector<string> split(const string& s, const string& delimeter) {
      if (s.size() == 0) {
        return {};
      }

      vector<string> words;

      int index = 0;

      while (s.find(delimeter, index) != string::npos) {
        const int nextDelimeterIndex = s.find(delimeter, index);
        const int length = nextDelimeterIndex - index;

        const string word = s.substr(index, length);
        words.push_back(word);

        index = nextDelimeterIndex + 1;
      }

      const string finalWord = s.substr(index);
      words.push_back(finalWord);

      return words;
    }

  public:
    bool wordPattern(string pattern, string s) {
      unordered_map<char, string> letterToWord;
      unordered_map<string, char> wordToLetter;

      vector<string> words = split(s, " ");

      if (pattern.size() != words.size()) {
        return false;
      }

      for (int i = 0; i < pattern.size(); ++i) {
        const char& letter = pattern[i];
        const string& word = words[i];

        const bool isViolatingBijection = (
          (letterToWord.contains(letter) && letterToWord[letter] != word)
          || (wordToLetter.contains(word) && wordToLetter[word] != letter)
        );

        if (isViolatingBijection) {
          return false;
        }

        letterToWord[letter] = word;
        wordToLetter[word] = letter;
      }

      return true;
    }
};
