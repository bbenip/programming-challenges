class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());

      vector<vector<int>> mergedIntervals;

      for (const auto& interval : intervals) {
        if (
          !mergedIntervals.empty()
          && mergedIntervals.back().back() >= interval.front()
        ) {
          mergedIntervals.back().back() = max(
            mergedIntervals.back().back(),
            interval.back()
          );
        } else {
          mergedIntervals.push_back(interval);
        }
      }

      return mergedIntervals;
    }
};
