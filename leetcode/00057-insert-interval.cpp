class Solution {
  public:
    vector<vector<int>> insert(
      vector<vector<int>>& intervals,
      vector<int>& newInterval
    ) {
      // Insert new interval
      bool isNewIntervalInserted = false;

      for (int i = 0; i < intervals.size(); ++i) {
        if (newInterval.front() < intervals[i].front()) {
          intervals.insert(intervals.begin() + i, newInterval);
          isNewIntervalInserted = true;
          break;
        }
      }

      if (!isNewIntervalInserted) {
        intervals.push_back(newInterval);
      }

      // Merge overlapping intervals
      int firstOverlapIndex = -1;
      int numberOfOverlappingIntervals = 0;

      for (int i = 0; i < intervals.size() - 1; ++i) {
        const vector<int>& overlapIntervalCandidate =
          numberOfOverlappingIntervals > 0
            ? intervals[firstOverlapIndex]
            : intervals[i];

        const bool isIntervalOverlap = (
          overlapIntervalCandidate.back() >= intervals[i + 1].front()
        );

        if (isIntervalOverlap) {
          if (numberOfOverlappingIntervals == 0) {
            firstOverlapIndex = i;
          }

          intervals[firstOverlapIndex].back() = max(
            intervals[firstOverlapIndex].back(),
            intervals[i + 1].back()
          );

          ++numberOfOverlappingIntervals;
        }
      }

      if (numberOfOverlappingIntervals > 0) {
        const auto first = intervals.begin() + firstOverlapIndex + 1;
        intervals.erase(first, first + numberOfOverlappingIntervals);
      }

      return intervals;
    }
};
