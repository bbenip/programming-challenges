class Solution {
  public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> squaredNums(nums.size());

      int smallestValueIndex = 0;
      int largestValueIndex = nums.size() - 1;

      while (smallestValueIndex <= largestValueIndex) {
        const int smallestValue = nums[smallestValueIndex];
        const int largestValue = nums[largestValueIndex];

        const int currentIndex = largestValueIndex - smallestValueIndex;

        if (abs(smallestValue) > largestValue) {
          squaredNums[currentIndex] = smallestValue * smallestValue;
          smallestValueIndex += 1;
        } else {
          squaredNums[currentIndex] = largestValue * largestValue;
          largestValueIndex -= 1;
        }
      }

      return squaredNums;
    }
};
