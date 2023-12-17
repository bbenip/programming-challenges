class Solution {
  private:
    void collate(
      vector<int>& nums,
      const int index1,
      const int midpointIndex,
      const int index2
    ) {
      vector<int> collatedArray;

      int leftIndex = index1;
      int rightIndex = midpointIndex;

      while (leftIndex < midpointIndex && rightIndex < index2) {
        const int element1 = nums[leftIndex];
        const int element2 = nums[rightIndex];

        if (element1 <= element2) {
          collatedArray.push_back(element1);
          leftIndex += 1;
        } else {
          collatedArray.push_back(element2);
          rightIndex += 1;
        }
      }

      if (leftIndex < midpointIndex) {
        collatedArray.insert(
          collatedArray.end(),
          nums.begin() + leftIndex,
          nums.begin() + midpointIndex
        );
      }

      if (rightIndex < index2) {
        collatedArray.insert(
          collatedArray.end(),
          nums.begin() + rightIndex,
          nums.begin() + index2
        );
      }

      for (int i = index1; i < index2; ++i) {
        nums[i] = collatedArray[i - index1];
      }
    }

    void sortArray(vector<int>& nums, int index1, int index2) {
      const int size = index2 - index1;

      if (size <= 1) {
        return;
      }

      const int midpointIndex = index1 + size / 2;

      sortArray(nums, index1, midpointIndex);
      sortArray(nums, midpointIndex, index2);

      collate(nums, index1, midpointIndex, index2);
    }

  public:
    vector<int> sortArray(vector<int>& nums) {
      sortArray(nums, 0, nums.size());

      return nums;
    }
};
