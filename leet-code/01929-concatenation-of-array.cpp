class Solution {
  public:
    vector<int> getConcatenation(vector<int>& nums) {
      vector<int> concatenatedArray(nums.size() * 2, 0);

      for (int i = 0; i < nums.size(); ++i) {
        concatenatedArray[i] = nums[i];
        concatenatedArray[i + nums.size()] = nums[i];
      }

      return concatenatedArray;
    }
};
