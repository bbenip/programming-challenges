class Solution {
  public:
    string removeStars(string s) {
      stack<char> characters;

      for (const auto& ch : s) {
        if (ch == '*') {
          characters.pop();
        } else {
          characters.push(ch);
        }
      }

      string result = "";

      while (!characters.empty()) {
        const char element = characters.top();

        result += element;

        characters.pop();
      }

      reverse(result.begin(), result.end());

      return result;
    }
};
