class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int indexLowerBound = 0;
      int indexUpperBound = nums.size() - 1;

      while (indexLowerBound <= indexUpperBound) {
        // Calculate average index without overflow
        const int indexDifference = indexUpperBound - indexLowerBound;
        const int indexCandidate = indexLowerBound + indexDifference / 2;

        const int num = nums[indexCandidate];

        if (num == target) {
          return indexCandidate;
        } else if (num < target) {
          indexLowerBound = indexCandidate + 1;
        } else if (num > target) {
          indexUpperBound = indexCandidate - 1;
        }
      }

      return -1;
    }
};
