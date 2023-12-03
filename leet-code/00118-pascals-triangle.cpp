class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> rows = { { 1 } };

      for (int i = 1; i < numRows; ++i) {
        const vector<int>& previousRow = rows[i - 1];
        vector<int> currentRow;

        for (int j = 0; j <= previousRow.size(); ++j) {
          if (j == 0 || j == previousRow.size()) {
            currentRow.push_back(1);
            continue;
          }

          const int addend1 = previousRow[j - 1];
          const int addend2 = previousRow[j];

          currentRow.push_back(addend1 + addend2);
        }

        rows.push_back(currentRow);
      }

      return rows;
    }
};
