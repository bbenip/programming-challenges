#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int getCycleLength(int n) {
  int cycleLength = 1;

  while (n != 1) {
    bool isEven = n % 2 == 0;

    if (isEven) {
      n /= 2;
    } else {
      n = (3 * n) + 1;
    }

    cycleLength += 1;
  }

  return cycleLength;
}

int main() {
  string line = "";

  while (getline(cin, line)) {
    istringstream inputStream(line);
    int i;
    int j;

    inputStream >> i;
    inputStream >> j;

    const int lowerBound = min(i, j);
    const int upperBound = max(i, j);

    int maxCycleLength = INT_MIN;

    for (int i = lowerBound; i <= upperBound; ++i) {
      const int cycleLength = getCycleLength(i);
      maxCycleLength = max(maxCycleLength, cycleLength);
    }

    cout << i << " " << j << " " << maxCycleLength << endl;
  }

  return 0;
}
