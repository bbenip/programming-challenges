class Solution {
  private:
    bool canFinishAtGivenSpeed(
      const vector<int>& piles,
      const int maxHours,
      const int speed
    ) {
      int totalNumberOfHours = 0;

      for (const auto& pile : piles) {
        int numberOfHoursToFinishCurrentPile = pile / speed;
        numberOfHoursToFinishCurrentPile += (pile % speed > 0) ? 1 : 0;

        totalNumberOfHours += numberOfHoursToFinishCurrentPile;

        if (totalNumberOfHours > maxHours) {
          return false;
        }
      }

      return true;
    }

  public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int lowerBound = 1;
      int upperBound = 1E9;

      while (lowerBound < upperBound) {
        const int speed = lowerBound + (upperBound - lowerBound) / 2;

        const bool isPossibleToFinish = canFinishAtGivenSpeed(piles, h, speed);

        if (isPossibleToFinish) {
          upperBound = speed;
        } else {
          lowerBound = speed + 1;
        }
      }

      return lowerBound;
    }
};
