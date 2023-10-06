#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, char> outcomeToShape = {
    { "AX", 'C' },
    { "AY", 'A' },
    { "AZ", 'B' },
    { "BX", 'A' },
    { "BY", 'B' },
    { "BZ", 'C' },
    { "CX", 'B' },
    { "CY", 'C' },
    { "CZ", 'A' },
  };

  unordered_map<char, char> outcomeToPoints = {
    { 'X', 0 },
    { 'Y', 3 },
    { 'Z', 6 },
  };

  int totalPoints = 0;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    char opponentShape = line[0];
    char outcome = line[2];

    string key = "";
    key.push_back(opponentShape);
    key.push_back(outcome);

    char myShape = outcomeToShape[key];

    totalPoints += myShape - 'A' + 1;
    totalPoints += outcomeToPoints[outcome];
  };

  cout << "The strategy guide yields: " << totalPoints << " points" << endl;
  return 0;
}
