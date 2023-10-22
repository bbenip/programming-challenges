#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> getBinData (istringstream& input) {
  const int numberOfBins = 3;

  vector<vector<int>> bins(numberOfBins, vector<int>(numberOfBins, -1));

  for (int i = 0; i < numberOfBins; ++i) {
    for (int j = 0; j < numberOfBins; ++j) {
      int numberOfBottles = -1;
      input >> numberOfBottles;

      bins[i][j] = numberOfBottles;
    }
  }

  return bins;
}

int getNumberOfMovements(
  const vector<vector<int>>& bins,
  const vector<int>& binTypes
) {
  int numberOfMovements = 0;

  for (int binIndex = 0; binIndex < bins.size(); ++binIndex) {
    for (int binTypeIndex = 0; binTypeIndex < binTypes.size(); ++binTypeIndex) {
      if (binTypeIndex == binTypes[binIndex]) {
        continue;
      }

      numberOfMovements += bins[binIndex][binTypeIndex];
    }
  }

  return numberOfMovements;
}

pair<string, int> getBinColorsAndMovements(const vector<vector<int>>& bins) {
  string optimalBinColors = "INVALID BIN COLORS";
  int minimumNumberOfMovements = INT_MAX;

  const vector<char> colors = { 'B', 'G', 'C' };

  for (int i = 0; i < bins.size(); ++i) {
    for (int j = 0; j < bins.size(); ++j) {
      if (i == j) {
        continue;
      }

      for (int k = 0; k < bins.size(); ++k) {
        if (i == k || j == k) {
          continue;
        }

        string binColors = "";
        binColors += colors[i];
        binColors += colors[j];
        binColors += colors[k];

        const vector<int> binTypes = { i, j, k };

        const int numberOfMovements = getNumberOfMovements(bins, binTypes);

        if (numberOfMovements == minimumNumberOfMovements) {
          optimalBinColors = min(optimalBinColors, binColors);
        } else if (numberOfMovements < minimumNumberOfMovements) {
          minimumNumberOfMovements = numberOfMovements;
          optimalBinColors = binColors;
        }
      }
    }
  }

  return { optimalBinColors, minimumNumberOfMovements };
}

int main() {
  string line = "";

  while (getline(cin, line)) {
    istringstream inputStream(line);

    vector<vector<int>> bins = getBinData(inputStream);

    const pair<string, int> binColorsAndMovements = getBinColorsAndMovements(bins);
    const string& binColors = binColorsAndMovements.first;
    const int& numberOfMovements = binColorsAndMovements.second;

    cout << binColors << " " << numberOfMovements << endl;
  }

  return 0;
}
