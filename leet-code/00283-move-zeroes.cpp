class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int indexOfFirstZero = -1;

      for (int i = 0; i < nums.size(); ++i) {
        int& currentNumber = nums[i];

        if (currentNumber == 0 && indexOfFirstZero == -1) {
          indexOfFirstZero = i;
        } else if (currentNumber != 0 && indexOfFirstZero != -1) {
          swap(currentNumber, nums[indexOfFirstZero]);
          indexOfFirstZero += 1;
        }
      }
    }
};
