class Codec {
  public:
    string encode(vector<string>& strs) {
      string encodedString = "";

      for (const auto& str : strs) {
        encodedString += str;
        encodedString += '\0';
      }

      return encodedString;
    }

    vector<string> decode(string s) {
      vector<string> decodedStrings;
      string currentString = "";

      for (const auto& character : s) {
        if (character == '\0') {
          decodedStrings.push_back(currentString);
          currentString = "";
        } else {
          currentString += character;
        }
      }

      return decodedStrings;
    }
};
