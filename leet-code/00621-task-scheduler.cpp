class Solution {
  public:
    int leastInterval(vector<char>& tasks, int n) {
      unordered_map<char, int> taskFrequency;

      int maxFrequency = 0;
      int numberOfTasksWithMaxFrequency = 0;

      for (const auto& task : tasks) {
        taskFrequency[task] += 1;

        const int currentFrequency = taskFrequency[task];

        if (currentFrequency > maxFrequency) {
          maxFrequency = currentFrequency;
          numberOfTasksWithMaxFrequency = 1;
        } else if (currentFrequency == maxFrequency) {
          numberOfTasksWithMaxFrequency += 1;
        }
      }

      const int timeRequiredForTasks = max(
        numberOfTasksWithMaxFrequency + (maxFrequency - 1) * (n + 1),
        (int) tasks.size()
      );

      return timeRequiredForTasks;
    }
};
