class Solution {
  private:
    bool isPalindrome(const string& s) {
      for (int i = 0; i < s.size() / 2; ++i) {
        int leftIndex = i;
        int rightIndex = s.size() - i - 1;

        if (s[leftIndex] != s[rightIndex]) {
          return false;
        }
      }

      return true;
    }

  public:
    string longestPalindrome(string s) {
      string palindrome = "";
      int palindromeLength = 0;

      for (int startIndex = 0; startIndex < s.size(); ++startIndex) {
        for (int endIndex = startIndex; endIndex < s.size(); ++endIndex) {
          int candidateLength = endIndex - startIndex + 1;

          if (candidateLength <= palindromeLength) {
            continue;
          }

          string candidate = s.substr(startIndex, candidateLength);

          if (isPalindrome(candidate)) {
            palindrome = candidate;
            palindromeLength = candidateLength;
          }
        }
      }

      return palindrome;
    }
};
