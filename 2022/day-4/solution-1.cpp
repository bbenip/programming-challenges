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

bool isCompleteOverlap(pair<int, int> assignment1, pair<int, int> assignment2) {
  return (
    (
      assignment1.first <= assignment2.first
      && assignment1.second >= assignment2.second
    ) || (
      assignment1.first >= assignment2.first
      && assignment1.second <= assignment2.second
    )
  );
}

int main() {
  int numCompleteOverlaps = 0;

  const char ASSIGNMENT_DELIMETER = ',';

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    const int delimeterIndex = line.find(ASSIGNMENT_DELIMETER);
    pair<int, int> assignment1 = extractPair(line.substr(0, delimeterIndex));
    pair<int, int> assignment2 = extractPair(line.substr(delimeterIndex + 1));

    if (isCompleteOverlap(assignment1, assignment2)) {
      ++numCompleteOverlaps;
    }
  }

  cout
    << "The number of assignment pairs with complete overlaps is: "
    << numCompleteOverlaps
    << endl;

  return 0;
}
