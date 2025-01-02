class Solution {
  public:
    vector<string> fizzBuzz(int n) {
      vector<string> answer;

      for (int i = 1; i <= n; ++i) {
        string result = "";

        if (i % 3 == 0 && i % 5 == 0) {
          result = "FizzBuzz";
        } else if (i % 3 == 0) {
          result = "Fizz";
        } else if (i % 5 == 0) {
          result = "Buzz";
        } else {
          result = to_string(i);
        }

        answer.push_back(result);
      }

      return answer;
    }
};
