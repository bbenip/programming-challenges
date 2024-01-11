class Solution {
  public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> stoneHeap(stones.begin(), stones.end());

      while (stoneHeap.size() > 1) {
        const int heaviestStone = stoneHeap.top();
        stoneHeap.pop();

        const int secondHeaviestStone = stoneHeap.top();
        stoneHeap.pop();

        const int remainingStone = heaviestStone - secondHeaviestStone;

        if (remainingStone > 0) {
          stoneHeap.push(remainingStone);
        }
      }

      if (stoneHeap.empty()) {
        return 0;
      }

      return stoneHeap.top();
    }
};
