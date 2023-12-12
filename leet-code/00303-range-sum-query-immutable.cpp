class NumArray {
  private:
    vector<int> leftSums;

  public:
    NumArray(vector<int>& nums) {
      int leftSum = 0;

      for (const auto& num : nums) {
        leftSum += num;
        leftSums.push_back(leftSum);
      }
    }

    int sumRange(int left, int right) {
      if (left == 0) {
        return leftSums[right];
      }

      return leftSums[right] - leftSums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
