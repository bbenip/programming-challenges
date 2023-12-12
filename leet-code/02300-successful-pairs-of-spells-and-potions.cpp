class Solution {
  private:
    int calculateSuccessfulPairsForGivenSpell(
      const int spell,
      const vector<int>& potions,
      long long success
    ) {
      int lowerBound = 0;
      int upperBound = potions.size();

      while (lowerBound < upperBound) {
        const int midpoint = lowerBound + (upperBound - lowerBound) / 2;
        const int potion = potions[midpoint];

        long long product = 1;
        product *= spell;
        product *= potion;

        const bool isSuccessful = product >= success;

        if (isSuccessful) {
          upperBound = midpoint;
        } else {
          lowerBound = midpoint + 1;
        }
      }

      int numSuccessfulPairs = potions.size() - lowerBound;

      return numSuccessfulPairs;
    }

  public:
    vector<int> successfulPairs(
      vector<int>& spells,
      vector<int>& potions,
      long long success
    ) {
      vector<int> pairs;

      sort(potions.begin(), potions.end());

      for (const auto& spell : spells) {
        const int successfulPairs = calculateSuccessfulPairsForGivenSpell(
          spell,
          potions,
          success
        );

        pairs.push_back(successfulPairs);
      }

      return pairs;
    }
};
