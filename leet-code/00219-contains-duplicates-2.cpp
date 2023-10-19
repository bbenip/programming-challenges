class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> previousIndicesOfNumbers;

      for (int i = 0; i < nums.size(); ++i) {
        const int number = nums[i];

        const bool isWithinKElementsOfPreviousOccurence = (
          previousIndicesOfNumbers.contains(number)
          && i - previousIndicesOfNumbers[number] <= k
        );

        if (isWithinKElementsOfPreviousOccurence) {
          return true;
        }

        previousIndicesOfNumbers[number] = i;
      }

      return false;
    }
};
