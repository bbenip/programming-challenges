class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int insertIndex = 2;
      int numberOfRemovedElements = 0;

      while (insertIndex + numberOfRemovedElements < nums.size()) {
        const int currentIndex = insertIndex + numberOfRemovedElements;

        const int previousPreviousElement = nums[insertIndex - 2];
        const int previousElement = nums[insertIndex - 1];
        const int currentElement = nums[currentIndex];

        const bool isToBeRemoved = (
          previousPreviousElement == previousElement
          && previousElement == currentElement
        );

        if (isToBeRemoved) {
          numberOfRemovedElements += 1;
        } else {
          nums[insertIndex] = currentElement;
          insertIndex += 1;
        }
      }

      const int numberOfRemainingElements = (
        nums.size() - numberOfRemovedElements
      );

      return numberOfRemainingElements;
    }
};
