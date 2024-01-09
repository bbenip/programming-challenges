class Solution {
  public:
    int trap(vector<int>& heights) {
      vector<int> maxHeightToLeft = heights;
      vector<int> maxHeightToRight = heights;

      for (int i = 1; i < heights.size(); ++i) {
        maxHeightToLeft[i] = max(maxHeightToLeft[i - 1], heights[i]);

        maxHeightToRight[heights.size() - 1 - i] = max(
          maxHeightToRight[heights.size() - i],
          heights[heights.size() - 1 - i]
        );
      }

      int trappedWater = 0;

      for (int i = 0; i < heights.size(); ++i) {
        const int currentMaxHeightToLeft = maxHeightToLeft[i];
        const int currentMaxHeightToRight = maxHeightToRight[i];

        const int currentHeight = heights[i];

        const bool isTrappedWater = (
          currentMaxHeightToLeft > currentHeight
          && currentMaxHeightToRight > currentHeight
        );

        if (isTrappedWater) {
          const int currentWaterTrapped = (
            min(currentMaxHeightToLeft, currentMaxHeightToRight) - currentHeight
          );

          trappedWater += currentWaterTrapped;
        }
      }

      return trappedWater;
    }
};
