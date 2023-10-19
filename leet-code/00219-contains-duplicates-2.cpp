class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      vector<pair<int, int>> numbersAndIndices;

      for (int i = 0; i < nums.size(); ++i) {
        const int currentNumber = nums[i];
        numbersAndIndices.push_back({ currentNumber, i } );
      }

      sort(
        numbersAndIndices.begin(),
        numbersAndIndices.end(),
        [] (const auto& numberAndIndex1, const auto& numberAndIndex2) {
          const auto& [number1, _index1] = numberAndIndex1;
          const auto& [number2, _index2] = numberAndIndex2;

          return number1 < number2;
        }
      );

      for (int i = 1; i < numbersAndIndices.size(); ++i) {
        const auto& [number1, index1] = numbersAndIndices[i - 1];
        const auto& [number2, index2] = numbersAndIndices[i];

        // Use abs() because sort is not guaranteed to be stable in C++
        // Do not use stable_sort as its runtime can be polyloglinear
        // i.e., O(n*(log(n))^2)
        if (number1 == number2 && abs(index2 - index1) <= k) {
          return true;
        }
      }

      return false;
    }
};
