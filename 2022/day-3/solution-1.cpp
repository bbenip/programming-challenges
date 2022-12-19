#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int getPriority(char itemType) {
  if (itemType >= 'A' && itemType <= 'Z') {
    return itemType - 'A' + 27;
  }

  return itemType - 'a' + 1;
}

int main() {
  vector<char> misplacedItemTypes;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    unordered_set<char> itemTypesInCompartment1;
    const int compartmentSize = line.size() / 2;

    for (int i = 0; i < compartmentSize; ++i) {
      itemTypesInCompartment1.insert(line[i]);
    }

    for (int i = 0; i < compartmentSize; ++i) {
      const char itemType = line[i + compartmentSize];

      if (itemTypesInCompartment1.contains(itemType)) {
        misplacedItemTypes.push_back(itemType);
        break;
      }
    }
  }

  int prioritySum = 0;

  for (auto& itemType : misplacedItemTypes) {
    prioritySum += getPriority(itemType);
  }

  cout
    << "The sum of priorities for improperly placed items is: "
    << prioritySum
    << endl;

  return 0;
}
