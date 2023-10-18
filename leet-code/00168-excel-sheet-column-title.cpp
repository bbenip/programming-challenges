class Solution {
  public:
    string convertToTitle(int columnNumber) {
      string title = "";

      while (columnNumber != 0) {
        const int base26Digit = (columnNumber - 1) % 26;
        const char titleCharacter = base26Digit + 'A';

        title += titleCharacter;

        columnNumber = (columnNumber - 1) / 26;
      }

      reverse(title.begin(), title.end());

      return title;
    }
};
