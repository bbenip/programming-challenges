class Solution {
  private:
    bool isShippableWithinDaysWithWeight(
      const vector<int>& weights,
      const int days,
      const int dailyWeightLimit
    ) {
      int daysRequiredToShip = 0;
      int currentWeight = 0;

      for (const auto& weight : weights) {
        if (weight > dailyWeightLimit) {
          return false;
        }

        if (currentWeight > dailyWeightLimit - weight) {
          daysRequiredToShip += 1;
          currentWeight = 0;
        }

        currentWeight += weight;
      }

      daysRequiredToShip += 1;

      return daysRequiredToShip <= days;
    }

  public:
    int shipWithinDays(vector<int>& weights, int days) {
      int weightLowerBound = 1;
      int weightUpperBound = INT_MAX;

      while (weightLowerBound < weightUpperBound) {
        // Calculate midpoint without overflow
        const int weightCandidate = (
          weightLowerBound + (weightUpperBound - weightLowerBound) / 2
        );

        if (isShippableWithinDaysWithWeight(weights, days, weightCandidate)) {
          weightUpperBound = weightCandidate;
        } else {
          weightLowerBound = weightCandidate + 1;
        }
      }

      return weightLowerBound;
    }
};
