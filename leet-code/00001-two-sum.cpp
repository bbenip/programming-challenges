class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> existingNumberToIndex;

      for (int i = 0; i < nums.size(); ++i) {
        const int currentNumber = nums[i];
        const int complement = target - currentNumber;

        if (existingNumberToIndex.contains(complement)) {
          return { existingNumberToIndex[complement], i };
        }

        existingNumberToIndex[currentNumber] = i;
      }

      return { -1, -1 };
    }
};
