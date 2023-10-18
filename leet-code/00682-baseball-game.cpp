class Solution {
  public:
    int calPoints(vector<string>& operations) {
      stack<int> record;

      for (const auto& operation : operations) {
        if (operation == "C") {
          record.pop();
        } else if (operation == "D") {
          const int lastScore = record.top();

          record.push(lastScore * 2);
        } else if (operation == "+") {
          const int lastScore = record.top();
          record.pop();

          const int secondLastScore = record.top();

          record.push(lastScore);
          record.push(secondLastScore + lastScore);
        } else {
          const int newScore = stoi(operation);

          record.push(newScore);
        }
      }

      int totalScore = 0;

      while (!record.empty()) {
        totalScore += record.top();
        record.pop();
      }

      return totalScore;
    }
};
