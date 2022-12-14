#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<char, char> shapeToPoints = {
    { 'X', 1 },
    { 'Y', 2 },
    { 'Z', 3 },
  };

  unordered_map<string, char> outcomeToPoints = {
    { "AX", 3 },
    { "AY", 6 },
    { "AZ", 0 },
    { "BX", 0 },
    { "BY", 3 },
    { "BZ", 6 },
    { "CX", 6 },
    { "CY", 0 },
    { "CZ", 3 },
  };

  int totalPoints = 0;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    char opponentShape = line[0];
    char myShape = line[2];

    string outcome = "";
    outcome.push_back(opponentShape);
    outcome.push_back(myShape);

    totalPoints += shapeToPoints[myShape];
    totalPoints += outcomeToPoints[outcome];
  };

  cout << "The strategy guide yields: " << totalPoints << " points" << endl;
  return 0;
}
