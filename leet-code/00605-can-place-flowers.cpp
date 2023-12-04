class Solution {
  public:
    bool canPlaceFlowers(vector<int>& flowerbed, int numberOfFlowersToPlant) {
      if (numberOfFlowersToPlant == 0) {
        return true;
      }

      for (int i = 0; i < flowerbed.size(); ++i) {
        const bool isCurrentPlotEmpty = flowerbed[i] == 0;

        if (!isCurrentPlotEmpty) {
          continue;
        }

        const bool isLeftPlotEmpty = i == 0 || flowerbed[i - 1] == 0;
        const bool isRightPlotEmpty = (
          i == flowerbed.size() - 1 || flowerbed[i + 1] == 0
        );

        if (isLeftPlotEmpty && isRightPlotEmpty) {
          numberOfFlowersToPlant -= 1;

          if (numberOfFlowersToPlant == 0) {
            return true;
          }

          // Skip the next plot since a flower would be planted in this plot
          i += 1;
        }
      }

      return false;
    }
};
