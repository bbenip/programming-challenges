class Solution {
  public:
    bool validateStackSequences(vector<int>& pushed, vector<int> popped) {
      stack<int> stackState;

      int pushedIndex = 0;
      int poppedIndex = 0;

      while (pushedIndex < pushed.size()) {
        const int pushedElement = pushed[pushedIndex];
        stackState.push(pushedElement);

        while (!stackState.empty() && poppedIndex < popped.size()) {
          const int stackElement = stackState.top();
          const int poppedElement = popped[poppedIndex];

          if (stackElement != poppedElement) {
            break;
          }

          stackState.pop();
          poppedIndex += 1;
        }

        pushedIndex += 1;
      }

      return stackState.size() == 0;
    }
};
