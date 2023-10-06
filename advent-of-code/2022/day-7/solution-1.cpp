#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

const int SMALL_DIRECTORY_MAX_SIZE = 100000;

void updateSizeSum(int& sizeSum, const int& size) {
  if (size > SMALL_DIRECTORY_MAX_SIZE) {
    return;
  }

  sizeSum += size;
}

void updateSizes(stack<int>& sizes, int& sizeSum) {
  const int currentSize = sizes.top();
  sizes.pop();

  updateSizeSum(sizeSum, currentSize);

  if (!sizes.empty()) {
    int& parentSize = sizes.top();
    parentSize += currentSize;
  }
}

void recursivelyUpdateSizes(stack<int>& sizes, int& sizeSum) {
  while (!sizes.empty()) {
    updateSizes(sizes, sizeSum);
  }
}

int main() {
  int smallDirectoriesSizeSum = 0;
  stack<int> directoriesSizes;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    istringstream ss(line);

    string marker = "";
    ss >> marker;

    if (marker != "$") {
      if (marker == "dir") {
        continue;
      }

      int fileSize = stoi(marker);
      int& currentDirectorySize = directoriesSizes.top();
      currentDirectorySize += fileSize;
    } else if (marker == "$") {
      string command = "";
      ss >> command;

      if (command != "cd") {
        continue;
      }

      string path = "";
      ss >> path;

      if (path == "..") {
        updateSizes(directoriesSizes, smallDirectoriesSizeSum);
      } else {
        directoriesSizes.push(0);
      }
    }
  }

  recursivelyUpdateSizes(directoriesSizes, smallDirectoriesSizeSum);

  cout
    << "The sum of sizes for directories with size at most "
    << SMALL_DIRECTORY_MAX_SIZE
    << " is: "
    << smallDirectoriesSizeSum
    << endl;

  return 0;
}
