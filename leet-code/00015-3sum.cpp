class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> triplets;

      sort(nums.begin(), nums.end());

      for (int i = 0; i < nums.size() - 2; i++) {
        const int numberAtI = nums[i];

        if (!triplets.empty() && triplets.back()[0] == numberAtI) {
          continue;
        }

        int index1 = i + 1;
        int index2 = nums.size() - 1;

        while (index1 < index2) {
          const int numberAtIndex1 = nums[index1];
          const int numberAtIndex2 = nums[index2];

          const int sum = numberAtI + numberAtIndex1 + numberAtIndex2;

          if (sum == 0) {
            const vector<int> currentTriplet = {
              numberAtI,
              numberAtIndex1,
              numberAtIndex2
            };

            const bool isExistingTriplet = (
              !triplets.empty()
              && triplets.back()[1] == currentTriplet[1]
              && triplets.back()[2] == currentTriplet[2]
            );

            if (!isExistingTriplet) {
              triplets.push_back(currentTriplet);
            }

            index1 += 1;
            index2 -= 1;
          } else if (sum > 0) {
            index2 -= 1;
          } else if (sum < 0) {
            index1 += 1;
          }
        }
      }

      return triplets;
    }
};
