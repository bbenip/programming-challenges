class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int startIndex = 0;
      int endIndex = 0;

      deque<pair<int, int>> monotonicDequeWithIndex;
      vector<int> maximumValues;

      while (endIndex < nums.size()) {
        if (
          !monotonicDequeWithIndex.empty()
          && monotonicDequeWithIndex.front().second <= endIndex - k
        ) {
          monotonicDequeWithIndex.pop_front();
        }

        const int currentNumber = nums[endIndex];

        while (
          !monotonicDequeWithIndex.empty()
          && currentNumber > monotonicDequeWithIndex.back().first
        ) {
          monotonicDequeWithIndex.pop_back();
        }

        monotonicDequeWithIndex.push_back({ currentNumber, endIndex });

        const int windowSize = endIndex - startIndex + 1;

        if (windowSize == k) {
          maximumValues.push_back(monotonicDequeWithIndex.front().first);
          startIndex += 1;
        }

        endIndex += 1;
      }

      return maximumValues;
    }
};
