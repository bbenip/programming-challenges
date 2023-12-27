class Solution {
  private:
    bool isValidRowsAndColumns(const vector<vector<char>>& board) {
      const int BOARD_DIMENSION = 9;

      for (int i = 0; i < BOARD_DIMENSION; ++i) {
        unordered_set<char> existingNumbersInRow;
        unordered_set<char> existingNumbersInColumn;

        for (int j = 0; j < BOARD_DIMENSION; ++j) {
          const char characterInRow = board[i][j];
          const char characterInColumn = board[j][i];

          if (characterInRow != '.') {
            if (existingNumbersInRow.contains(characterInRow)) {
              return false;
            }

            existingNumbersInRow.insert(characterInRow);
          }

          if (characterInColumn != '.') {
            if (existingNumbersInColumn.contains(characterInColumn)) {
              return false;
            }

            existingNumbersInColumn.insert(characterInColumn);
          }
        }
      }

      return true;
    }

    bool isValidSubBox(
      const vector<vector<char>>& board,
      const int startingRow,
      const int startingColumn
    ) {
      unordered_set<char> existingNumbersInSubBox;

      const int SUB_BOX_DIMENSION = 3;

      for (int i = 0; i < SUB_BOX_DIMENSION; ++i) {
        for (int j = 0; j < SUB_BOX_DIMENSION; ++j) {
          const int row = i + startingRow;
          const int column = j + startingColumn;

          const char currentNumber = board[row][column];

          if (currentNumber == '.') {
            continue;
          }

          if (existingNumbersInSubBox.contains(currentNumber)) {
            return false;
          }

          existingNumbersInSubBox.insert(currentNumber);
        }
      }

      return true;
    }

    bool isValidSubBoxes(const vector<vector<char>>& board) {
      const int BOARD_DIMENSION = 9;
      const int SUB_BOX_DIMENSION = 3;

      for (int i = 0; i < BOARD_DIMENSION; i += SUB_BOX_DIMENSION) {
        for (int j = 0; j < BOARD_DIMENSION; j += SUB_BOX_DIMENSION) {
          if (!isValidSubBox(board, i, j)) {
            return false;
          }
        }
      }

      return true;
    }

  public:
    bool isValidSudoku(vector<vector<char>>& board) {
      return (
        isValidRowsAndColumns(board)
        && isValidSubBoxes(board)
      );
    }
};
