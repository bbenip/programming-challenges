class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      int indexLowerBound = 0;
      int indexUpperBound = nums.size();

      while (indexLowerBound < indexUpperBound) {
        // Calculate midway index without overflow
        const int indexCandidate =
          indexLowerBound
          + (indexUpperBound - indexLowerBound) / 2;

        const int currentElement = nums[indexCandidate];

        if (currentElement == target) {
          return indexCandidate;
        } else if (currentElement > target) {
          indexUpperBound = indexCandidate;
        } else if (currentElement < target) {
          indexLowerBound = indexCandidate + 1;
        }
      }

      return indexUpperBound;
    }
};
