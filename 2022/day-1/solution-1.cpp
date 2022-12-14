#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  int currentCalories = 0;
  int maxCalories = 0;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    if (line == "") {
      maxCalories = max(maxCalories, currentCalories);
      currentCalories = 0;
    } else {
      int caloriesInItem = stoi(line);
      currentCalories += caloriesInItem;
    }
  }

  maxCalories = max(maxCalories, currentCalories);

  cout << "The maximum calories that a single Elf is carrying is: " << maxCalories << endl;

  return 0;
}
