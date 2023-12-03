class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int numberOfRemainingElements = 0;

      for (int i = 0; i < nums.size(); ++i) {
        const int& currentNumber = nums[i];

        if (currentNumber != val) {
          nums[numberOfRemainingElements] = currentNumber;
          numberOfRemainingElements += 1;
        }
      }

      return numberOfRemainingElements;
    }
};
