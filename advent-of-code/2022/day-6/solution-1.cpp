#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
  const int MARKER_LENGTH = 4;

  ifstream file("input.txt");
  string buffer = "";

  getline(file, buffer);

  int bufferIndex = 0;
  int numUniqueCharacters = 0;
  bool isMarkerInBuffer = false;

  unordered_map<char, int> characterFrequencyMap;

  while (bufferIndex < buffer.size()) {
    if (bufferIndex >= MARKER_LENGTH) {
      const char nonMarkerCharacter = buffer[
        bufferIndex - MARKER_LENGTH
      ];

      --characterFrequencyMap[nonMarkerCharacter];

      const int frequency = characterFrequencyMap[nonMarkerCharacter];

      if (frequency == 0) {
        --numUniqueCharacters;
      } else if (frequency == 1) {
        ++numUniqueCharacters;
      }
    }

    const char currentCharacter = buffer[bufferIndex];
    ++characterFrequencyMap[currentCharacter];

    if (characterFrequencyMap[currentCharacter] == 1) {
      ++numUniqueCharacters;
    } else if (characterFrequencyMap[currentCharacter] == 2) {
      --numUniqueCharacters;
    }

    if (numUniqueCharacters == MARKER_LENGTH) {
      isMarkerInBuffer = true;
      break;
    }

    ++bufferIndex;
  }

  if (!isMarkerInBuffer) {
    cout << "No start of packet marker was found!" << endl;
    return 0;
  }

  const int numCharactersProcessed = bufferIndex + 1;

  cout
    << "The number of characters to process to get the marker is: "
    << numCharactersProcessed
    << endl;

  return 0;
}
