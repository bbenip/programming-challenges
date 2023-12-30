class Solution {
  private:
    void generateParentheses(
      const string state,
      const int n,
      const int numberOfOpenParentheses,
      const int numberOfCloseParentheses,
      vector<string>& solutions
    ) {
      if (
        numberOfOpenParentheses > n
        || numberOfCloseParentheses > numberOfOpenParentheses
      ) {
        return;
      }

      if (numberOfOpenParentheses == n && numberOfCloseParentheses == n) {
        solutions.push_back(state);
        return;
      }

      generateParentheses(
        state + '(',
        n,
        numberOfOpenParentheses + 1,
        numberOfCloseParentheses,
        solutions
      );

      generateParentheses(
        state + ')',
        n,
        numberOfOpenParentheses,
        numberOfCloseParentheses + 1,
        solutions
      );
    }

  public:
    vector<string> generateParenthesis(int n) {
      vector<string> solutions;

      generateParentheses("", n, 0, 0, solutions);

      return solutions;
    }
};
