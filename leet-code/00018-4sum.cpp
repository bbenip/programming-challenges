class Solution {
  private:
    int getDifferenceToTarget(const vector<int>& nums, int target) {
      int startIndex = 0;
      int endIndex = ((int) nums.size()) - 1;

      while (startIndex <= endIndex) {
        if (target >= 0) {
          if (nums[endIndex] < 0) {
            return -1;
          }

          target -= nums[endIndex];
          endIndex -= 1;
        } else {
          if (nums[startIndex] > 0) {
            return 1;
          }

          target -= nums[startIndex];
          startIndex += 1;
        }
      }

      if (target > 0) {
        return -1;
      }

      if (target < 0) {
        return 1;
      }

      return 0;
    }


  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());

      vector<vector<int>> quadruplets;

      const int size = nums.size();

      for (int i = 0; i < size - 3; ++i) {
        const int num1 = nums[i];

        if (!quadruplets.empty() && quadruplets.back()[0] == num1) {
          continue;
        }

        for (int j = i + 1; j < size - 2; ++j) {
          const int num2 = nums[j];

          if (
            !quadruplets.empty()
            && quadruplets.back()[0] == num1
            && quadruplets.back()[1] == num2
          ) {
            continue;
          }

          int index1 = j + 1;
          int index2 = size - 1;

          while (index1 < index2) {
            const int num3 = nums[index1];
            const int num4 = nums[index2];

            const vector<int> candidateSolution = { num1, num2, num3, num4 };

            const int differenceToTarget = getDifferenceToTarget(
              candidateSolution,
              target
            );

            if (differenceToTarget == 0) {
              const bool isUniqueSolution = (
                quadruplets.empty()
                || quadruplets.back()[0] != num1
                || quadruplets.back()[1] != num2
                || quadruplets.back()[2] != num3
              );

              if (isUniqueSolution) {
                quadruplets.push_back(candidateSolution);
              }

              index1 += 1;
              index2 -= 1;
            } else if (differenceToTarget > 0) {
              index2 -= 1;
            } else if (differenceToTarget < 0) {
              index1 += 1;
            }
          }
        }
      }

      return quadruplets;
    }
};
