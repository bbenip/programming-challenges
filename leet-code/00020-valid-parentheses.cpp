class Solution {
  private:
    bool isOpenParanthesis(const char paranthesis) {
      return paranthesis == '(' || paranthesis == '[' || paranthesis == '{';
    }

    bool isMatchingParantheses(
      const char openParanthesis,
      const char closeParanthesis
    ) {
      return (
        openParanthesis == '(' && closeParanthesis == ')'
        || openParanthesis == '[' && closeParanthesis == ']'
        || openParanthesis == '{' && closeParanthesis == '}'
      );
    }

  public:
    bool isValid(string s) {
      stack<int> openParantheses;

      for (auto& paranthesis : s) {
        if (isOpenParanthesis(paranthesis)) {
          openParantheses.push(paranthesis);
        } else {
          if (openParantheses.empty()) {
            return false;
          }

          const char openParanthesis = openParantheses.top();

          if (!isMatchingParantheses(openParanthesis, paranthesis)) {
            return false;
          }

          openParantheses.pop();
        }
      }

      return openParantheses.empty();
    }
};
