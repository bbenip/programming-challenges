#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int calculateStackCount() {
  int stackCount = 0;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    if (line == "") {
      break;
    }

    if (line.find('[') != string::npos) {
      continue;
    }

    istringstream ss(line);

    string element = "";
    while (ss >> element) {
      ++stackCount;
    }
  }

  return stackCount;
}

string getStackTops(vector<deque<string>>& stacks) {
  string result = "";

  for (auto& stack : stacks) {
    if (stack.size() == 0) {
      continue;
    }

    result += stack.front();
  }

  return result;
}

int main() {
  const int NUM_STACKS = calculateStackCount();
  const string CRATE_EXAMPLE = "A";
  const int CRATE_SIZE = CRATE_EXAMPLE.size();
  const string RAW_CRATE_EXAMPLE = "[A]";
  const int RAW_CRATE_SIZE = RAW_CRATE_EXAMPLE.size();

  ifstream file("input.txt");
  string line = "";

  bool isInstruction = false;
  vector<deque<string>> crateStacks(NUM_STACKS);

  while (getline(file, line)) {
    if (line == "") {
      isInstruction = true;
      continue;
    }

    if (!isInstruction) {
      if (line.find('[') == string::npos) {
        continue;
      }

      for (int i = 0; i < NUM_STACKS; ++i) {
        const int startIndex = i * (RAW_CRATE_SIZE + 1) + 1;

        if (startIndex > line.size()) {
          break;
        }

        string crate = line.substr(startIndex, CRATE_SIZE);

        if (crate == " ") {
          continue;
        }

        crateStacks[i].push_back(crate);
      }
    } else {
      istringstream ss(line);

      string word = "";
      string quantityString = "";
      string index1String = "";
      string index2String = "";

      ss >> word >> quantityString;
      ss >> word >> index1String;
      ss >> word >> index2String;

      const int quantity = stoi(quantityString);
      const int index1 = stoi(index1String) - 1;
      const int index2 = stoi(index2String) - 1;

      vector<string> cratesInTransit;
      for (int i = 0; i < quantity; ++i) {
        string crate = crateStacks[index1].front();
        crateStacks[index1].pop_front();

        cratesInTransit.push_back(crate);
      }

      crateStacks[index2].insert(
        crateStacks[index2].begin(),
        cratesInTransit.begin(),
        cratesInTransit.end()
      );
    }
  }

  const string stackTops = getStackTops(crateStacks);

  cout
    << "The final arrangement of the top crates on each stack is: "
    << stackTops
    << endl;

  return 0;
}
