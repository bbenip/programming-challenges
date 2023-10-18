#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void printPiles(const vector<vector<int>>& piles) {
  for (int i = 0; i < piles.size(); ++i) {
    cout << i << ":";

    for (const auto& block : piles[i]) {
      cout << " " << block;
    }

    cout << endl;
  }
}

void putBackBlocksAbove(
  const int block,
  vector<vector<int>>& piles,
  vector<int>& blockToPileIndex
) {
  const int pileIndex = blockToPileIndex[block];
  vector<int>& pile = piles[pileIndex];

  int topBlockInPile = pile.back();

  while (topBlockInPile != block) {
    vector<int>& originalPile = piles[topBlockInPile];

    originalPile.push_back(topBlockInPile);
    pile.pop_back();

    blockToPileIndex[topBlockInPile] = topBlockInPile;

    topBlockInPile = pile.back();
  }
}

int getBlockIndexInPile(const int targetBlock, const vector<int>& pile) {
  for (int i = 0; i < pile.size(); ++i) {
    const int block = pile[i];

    if (block == targetBlock) {
      return i;
    }
  }

  return -1;
}

void moveBlocksFromSourceToDestination(
  const int sourceBlock,
  const int destinationBlock,
  vector<vector<int>>& piles,
  vector<int>& blockToPileIndex
) {
  const int sourcePileIndex = blockToPileIndex[sourceBlock];
  const int destinationPileIndex = blockToPileIndex[destinationBlock];

  vector<int>& sourcePile = piles[sourcePileIndex];
  vector<int>& destinationPile = piles[destinationPileIndex];

  const int sourceBlockIndex = getBlockIndexInPile(sourceBlock, sourcePile);

  const int numBlocksToMove = sourcePile.size() - sourceBlockIndex;

  for (int i = 0; i < numBlocksToMove; ++i) {
    const int block = sourcePile[sourceBlockIndex + i];

    blockToPileIndex[block] = destinationPileIndex;
  }

  destinationPile.insert(
    destinationPile.end(),
    sourcePile.begin() + sourceBlockIndex,
    sourcePile.end()
  );

  sourcePile.erase(
    sourcePile.begin() + sourceBlockIndex,
    sourcePile.end()
  );
}

int main() {
  int numberOfBlocks = -1;
  cin >> numberOfBlocks;
  cin.ignore();

  vector<int> blockToPileIndex(numberOfBlocks, -1);
  vector<vector<int>> piles(numberOfBlocks);

  for (int i = 0; i < numberOfBlocks; ++i) {
    blockToPileIndex[i] = i;
    piles[i].push_back(i);
  }

  string line = "";

  while (getline(cin, line)) {
    if (line == "quit") {
      break;
    }

    string operation = "";
    int sourceBlock = -1;
    string targetLocation = "";
    int destinationBlock = -1;

    istringstream inputStream(line);
    inputStream >> operation;
    inputStream >> sourceBlock;
    inputStream >> targetLocation;
    inputStream >> destinationBlock;

    const int sourcePileIndex = blockToPileIndex[sourceBlock];
    const int destinationPileIndex = blockToPileIndex[destinationBlock];

    const vector<int>& sourcePile = piles[sourcePileIndex];
    const vector<int>& destinationPile = piles[destinationPileIndex];

    if (sourcePile == destinationPile) {
      continue;
    }

    if (operation == "move") {
      putBackBlocksAbove(sourceBlock, piles, blockToPileIndex);
    }

    if (targetLocation == "onto") {
      putBackBlocksAbove(destinationBlock, piles, blockToPileIndex);
    }

    moveBlocksFromSourceToDestination(
      sourceBlock,
      destinationBlock,
      piles,
      blockToPileIndex
    );
  }

  printPiles(piles);
}
