class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> anagramGroups;

      unordered_map<string, int> stringToGroupIndex;

      for (const auto& str : strs) {
        string sortedString = str;
        sort(sortedString.begin(), sortedString.end());

        if (!stringToGroupIndex.contains(sortedString)) {
          anagramGroups.push_back({});
          stringToGroupIndex[sortedString] = stringToGroupIndex.size();
        }

        const int anagramGroupIndex = stringToGroupIndex[sortedString];
        anagramGroups[anagramGroupIndex].push_back(str);
      }

      return anagramGroups;
    }
};
