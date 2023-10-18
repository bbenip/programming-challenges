class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visitedNumbers;

        for (auto& num : nums) {
          if (visitedNumbers.contains(num)) {
            return true;
          }

          visitedNumbers.insert(num);
        }

        return false;
    }
};
