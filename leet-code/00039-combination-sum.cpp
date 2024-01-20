class Solution {
  private:
    void combinationSum(
      const vector<int>& candidates,
      const int startIndex,
      const int target,
      vector<int>& state,
      vector<vector<int>>& solutions
    ) {
      if (target < 0) {
        return;
      }

      if (target == 0) {
        solutions.push_back(state);
        return;
      }

      for (int i = startIndex; i < candidates.size(); ++i) {
        const int number = candidates[i];

        if (number > target) {
          break;
        }

        state.push_back(number);

        combinationSum(candidates, i, target - number, state, solutions);

        state.pop_back();
      }
    }

  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());

      vector<int> state;
      vector<vector<int>> solutions;

      combinationSum(candidates, 0, target, state, solutions);

      return solutions;
    }
};
