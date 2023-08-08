#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> getMinAdjacentHeights(
  const vector<vector<int>>& treeHeights
) {
  const int numRows = treeHeights.size();
  const int numColumns = treeHeights[0].size();

  vector<vector<int>> tallestTreeToLeft(numRows, vector<int>(numColumns));

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numColumns; ++j) {
      if (j == 0) {
        tallestTreeToLeft[i][j] = -1;
      } else {
        tallestTreeToLeft[i][j] = max(
          tallestTreeToLeft[i][j - 1],
          treeHeights[i][j - 1]
        );
      }
    }
  }

  vector<vector<int>> tallestTreeToRight(numRows, vector<int>(numColumns));

  for (int i = 0; i < numRows; ++i) {
    for (int j = numColumns - 1; j >= 0; --j) {
      if (j == numColumns - 1) {
        tallestTreeToRight[i][j] = -1;
      } else {
        tallestTreeToRight[i][j] = max(
          tallestTreeToRight[i][j + 1],
          treeHeights[i][j + 1]
        );
      }
    }
  }

  vector<vector<int>> tallestTreeAbove(numRows, vector<int>(numColumns));

  for (int j = 0; j < numColumns; ++j) {
    for (int i = 0; i < numRows; ++i) {
      if (i == 0) {
        tallestTreeAbove[i][j] = -1;
      } else {
        tallestTreeAbove[i][j] = max(
          tallestTreeAbove[i - 1][j],
          treeHeights[i - 1][j]
        );
      }
    }
  }

  vector<vector<int>> tallestTreeBelow(numRows, vector<int>(numColumns));

  for (int j = 0; j < numColumns; ++j) {
    for (int i = numRows - 1; i >= 0; --i) {
      if (i == numRows - 1) {
        tallestTreeBelow[i][j] = -1;
      } else {
        tallestTreeBelow[i][j] = max(
          tallestTreeBelow[i + 1][j],
          treeHeights[i + 1][j]
        );
      }
    }
  }

  vector<vector<int>> minAdjacentHeights(numRows, vector<int>(numColumns));

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numColumns; ++j) {
      minAdjacentHeights[i][j] = min(
        min(tallestTreeToLeft[i][j], tallestTreeToRight[i][j]),
        min(tallestTreeAbove[i][j], tallestTreeBelow[i][j])
      );
    }
  }

  return minAdjacentHeights;
}

int countVisibleTrees(
  vector<vector<int>>& treeHeights,
  const vector<vector<int>>& minAdjacentHeights
) {
  int count = 0;

  const int numRows = treeHeights.size();
  const int numColumns = treeHeights[0].size();

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numColumns; ++j) {
      if (treeHeights[i][j] > minAdjacentHeights[i][j]) {
        ++count;
      }
    }
  }

  return count;
}

int main() {
  vector<vector<int>> treeHeights;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    vector<int> treeHeightRow;

    for (const auto& heightChar : line) {
      treeHeightRow.push_back(heightChar - '0');
    }

    treeHeights.push_back(treeHeightRow);
  }

  vector<vector<int>> minAdjacentHeights = getMinAdjacentHeights(treeHeights);

  int numVisibleTrees = countVisibleTrees(treeHeights, minAdjacentHeights);

  cout << "The number of visible trees is: " << numVisibleTrees << endl;
}
