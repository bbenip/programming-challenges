class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      const int m = matrix.size();
      const int n = matrix.back().size();

      int lowerBound = 0;
      int upperBound = m * n - 1;

      while (lowerBound <= upperBound) {
        const int index = lowerBound + (upperBound - lowerBound) / 2;

        const int mIndex = index / n;
        const int nIndex = index % n;

        const int candidate = matrix[mIndex][nIndex];

        if (candidate == target) {
          return true;
        }

        if (candidate < target) {
          lowerBound = index + 1;
        } else {
          upperBound = index - 1;
        }
      }

      return false;
    }
};
