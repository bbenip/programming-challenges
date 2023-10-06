#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int getPriority(char itemType) {
  if (itemType >= 'A' && itemType <= 'Z') {
    return itemType - 'A' + 27;
  }

  return itemType - 'a' + 1;
}

bool getRucksacks(ifstream& file, vector<string>& rucksacks) {
  const int numRucksacks = rucksacks.size();

  for (int i = 0; i < numRucksacks; ++i) {
    if (!getline(file, rucksacks[i])) {
      return false;
    }
  }

  return true;
}


int main() {
  const int NUM_RUCKSACKS_PER_GROUP = 3;

  vector<char> badgeItemTypes;

  ifstream file("input.txt");
  vector<string> rucksacks(NUM_RUCKSACKS_PER_GROUP, "");

  while (getRucksacks(file, rucksacks)) {
    unordered_map<char, int> itemTypesRucksackFrequency;

    for (auto& rucksack : rucksacks) {
      unordered_set<char> itemTypesInRucksack;

      for (auto& itemType : rucksack) {
        if (itemTypesInRucksack.contains(itemType)) {
          continue;
        }

        itemTypesInRucksack.insert(itemType);

        if (itemTypesRucksackFrequency.contains(itemType)) {
          itemTypesRucksackFrequency[itemType] += 1;

          if (itemTypesRucksackFrequency[itemType] == rucksacks.size()) {
            badgeItemTypes.push_back(itemType);
            break;
          }
        } else {
          itemTypesRucksackFrequency[itemType] = 1;
        }
      }
    }
  }

  int prioritySum = 0;

  for (auto& itemType : badgeItemTypes) {
    prioritySum += getPriority(itemType);
  }

  cout
    << "The sum of priorities for the badge item types is: "
    << prioritySum
    << endl;

  return 0;
}
