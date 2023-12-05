class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
      int indexLowerBound = 0;
      int indexUpperBound = nums.size() - 1;

      while (indexLowerBound < indexUpperBound) {
        int index = indexLowerBound + (indexUpperBound - indexLowerBound) / 2;
        int candidate = nums[index];

        if (nums[index] < nums[index + 1]) {
          indexLowerBound = index + 1;
        } else {
          indexUpperBound = index;
        }
      }

      return indexLowerBound;
    }
};
