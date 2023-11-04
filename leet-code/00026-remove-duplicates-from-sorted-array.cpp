class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int numberOfUniqueElements = 0;

      for (int i = 0; i < nums.size(); ++i) {
        const bool isUniqueElement = (
          numberOfUniqueElements == 0
          || nums[i] != nums[numberOfUniqueElements - 1]
        );

        if (isUniqueElement) {
          swap(nums[i], nums[numberOfUniqueElements]);
          numberOfUniqueElements += 1;
        }
      }

      return numberOfUniqueElements;
    }
};
