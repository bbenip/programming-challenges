class Solution {
  public:
    vector<int> findArray(vector<int>& pref) {
      vector<int> output(pref);

      for (int i = 1; i < output.size(); ++i) {
        output[i] = pref[i] ^ pref[i - 1];
      }

      return output;
    }
};
