class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> answer(temperatures.size(), 0);
      stack<int> nonIncreasingTemperatureDays;

      for (int day = 0; day < temperatures.size(); ++day) {
        const int currentTemperature = temperatures[day];

        while (!nonIncreasingTemperatureDays.empty()) {
          const int previousDay = nonIncreasingTemperatureDays.top();
          const int previousTemperature = temperatures[previousDay];

          if (currentTemperature <= previousTemperature) {
            break;
          }

          answer[previousDay] = day - previousDay;

          nonIncreasingTemperatureDays.pop();
        }

        nonIncreasingTemperatureDays.push(day);
      }

      return answer;
    }
};
