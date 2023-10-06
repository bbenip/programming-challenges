#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void updateMaxList(vector<int>& list, int value) {
  int size = list.size();

  for (int i = 0; i < size; ++i) {
    if (value >= list[i]) {
      list.insert(list.begin() + i, value);
      break;
    }
  }

  list.resize(size);
}

int main() {
  int currentCalories = 0;
  vector<int> maxCaloriesList = vector<int>(3, 0);

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    if (line == "") {
      updateMaxList(maxCaloriesList, currentCalories);
      currentCalories = 0;
    } else {
      int caloriesInItem = stoi(line);
      currentCalories += caloriesInItem;
    }
  }

  updateMaxList(maxCaloriesList, currentCalories);

  int sumOfInterest = 0;
  for (auto& value : maxCaloriesList) {
    sumOfInterest += value;
  }

  cout
    << "The sum of calories of the top 3 Elves is: "
    << sumOfInterest
    << endl;

  return 0;
}
