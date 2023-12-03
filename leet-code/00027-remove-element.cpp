class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int numberOfRemovedElements = 0;

      for (int i = nums.size() - 1; i >= 0; --i) {
        int& currentNumber = nums[i];

        if (currentNumber == val) {
          // This element can only be val if all the elements after are also val
          // In this case, the following procedure is still correct
          int& lastNonValNumber = nums[
            nums.size() - 1 - numberOfRemovedElements
          ];

          swap(currentNumber, lastNonValNumber);
          numberOfRemovedElements += 1;
        }
      }

      const int numberOfRemainingElements = (
        nums.size() - numberOfRemovedElements
      );

      return numberOfRemainingElements;
    }
};
