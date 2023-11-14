class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int index1 = 0;
      int index2 = numbers.size() - 1;

      while (index1 < index2) {
        const int number1 = numbers[index1];
        const int number2 = numbers[index2];

        const int sum = number1 + number2;

        if (sum == target) {
          return { index1 + 1, index2 + 1 };
        } else if (sum < target) {
          index1 += 1;
        } else if (sum > target) {
          index2 -= 1;
        }
      }

      return { -1, -1 };
    }
};
