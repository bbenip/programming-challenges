class Solution {
  public:
    int totalFruit(vector<int>& fruits) {
      int startIndex = 0;
      int endIndex = 0;

      int maximumNumberOfFruits = 0;

      unordered_map<int, int> fruitFrequency;

      while (endIndex < fruits.size()) {
        const int lastFruit = fruits[endIndex];

        fruitFrequency[lastFruit] += 1;

        while (fruitFrequency.size() > 2) {
          const int firstFruit = fruits[startIndex];
          fruitFrequency[firstFruit] -= 1;

          if (fruitFrequency[firstFruit] == 0) {
            fruitFrequency.erase(firstFruit);
          }

          startIndex += 1;
        }

        const int currentNumberOfFruits = endIndex - startIndex + 1;

        maximumNumberOfFruits = max(
          maximumNumberOfFruits,
          currentNumberOfFruits
        );

        endIndex += 1;
      }

      return maximumNumberOfFruits;
    }
};
