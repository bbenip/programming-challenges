class Solution {
  public:
    void search(
      vector<vector<int>>& solutions,
      vector<int>& state,
      const vector<int>& nums,
      const int index
    ) {
      solutions.push_back(state);

      for (int i = index; i < nums.size(); ++i) {
        state.push_back(nums[i]);
        search(solutions, state, nums, i + 1);
        state.pop_back();
      }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> solutions;
      vector<int> state;

      search(solutions, state, nums, 0);

      return solutions;
    }
};
