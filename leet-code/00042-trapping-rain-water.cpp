class Solution {
  public:
    int trap(vector<int>& heights) {
      int trappedWater = 0;

      int leftIndex = 0;
      int rightIndex = heights.size() - 1;

      int leftMaxHeight = 0;
      int rightMaxHeight = 0;

      while (leftIndex <= rightIndex) {
        if (leftMaxHeight < rightMaxHeight) {
          leftMaxHeight = max(leftMaxHeight, heights[leftIndex]);
          trappedWater += leftMaxHeight - heights[leftIndex];

          leftIndex += 1;
        } else {
          rightMaxHeight = max(rightMaxHeight, heights[rightIndex]);
          trappedWater += rightMaxHeight - heights[rightIndex];

          rightIndex -= 1;
        }
      }

      return trappedWater;
    }
};
