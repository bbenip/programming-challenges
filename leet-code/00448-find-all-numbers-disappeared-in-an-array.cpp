class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      unordered_set<int> existingNumbers(nums.begin(), nums.end());

      vector<int> missingNumbers;

      for (int i = 0 ; i < nums.size(); ++i) {
        const int expectedNumber = i + 1;

        if (!existingNumbers.contains(expectedNumber)) {
          missingNumbers.push_back(expectedNumber);
        }
      }

      return missingNumbers;
    }
};
