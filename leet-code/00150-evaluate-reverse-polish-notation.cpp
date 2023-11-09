class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      stack<int> operands;

      const string operators = "+-*/";

      for (const auto& token : tokens) {
        const bool isOperand = operators.find(token) == string::npos;

        if (isOperand) {
          operands.push(stoi(token));
          continue;
        }

        const int operand2 = operands.top();
        operands.pop();

        const int operand1 = operands.top();
        operands.pop();

        if (token == "+") {
          operands.push(operand1 + operand2);
        } else if (token == "-") {
          operands.push(operand1 - operand2);
        } else if (token == "*") {
          operands.push(operand1 * operand2);
        } else if (token == "/") {
          operands.push(operand1 / operand2);
        }
      }

      const int value = operands.top();
      operands.pop();

      return value;
    }
};
