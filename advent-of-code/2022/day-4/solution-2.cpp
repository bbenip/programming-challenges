#include <fstream>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, int> extractPair(string assignment) {
  const char RANGE_DELIMETER = '-';
  const int delimeterIndex = assignment.find(RANGE_DELIMETER);

  int start = stoi(assignment.substr(0, delimeterIndex));
  int end = stoi(assignment.substr(delimeterIndex + 1));

  return { start, end };
}

bool isAnyOverlap(pair<int, int> assignment1, pair<int, int> assignment2) {
  return (
    (
      assignment2.first >= assignment1.first
      && assignment2.first <= assignment1.second
    ) || (
      assignment1.first >= assignment2.first
      && assignment1.first <= assignment2.second
    )
  );
}

int main() {
  int numOverlaps = 0;

  const char ASSIGNMENT_DELIMETER = ',';

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    const int delimeterIndex = line.find(ASSIGNMENT_DELIMETER);
    pair<int, int> assignment1 = extractPair(line.substr(0, delimeterIndex));
    pair<int, int> assignment2 = extractPair(line.substr(delimeterIndex + 1));

    if (isAnyOverlap(assignment1, assignment2)) {
      ++numOverlaps;
    }
  }

  cout
    << "The number of assignment pairs with any overlap is: "
    << numOverlaps
    << endl;

  return 0;
}
