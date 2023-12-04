class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, char> characterMap;
      unordered_set<char> mappedToCharacters;

      for (int i = 0; i < t.size(); ++i) {
        const char characterInS = s[i];
        const char characterInT = t[i];

        if (!characterMap.contains(characterInS)) {
          if (mappedToCharacters.contains(characterInT)) {
            return false;
          }

          characterMap[characterInS] = characterInT;
          mappedToCharacters.insert(characterInT);
        }

        const char expectedCharacterInT = characterMap[characterInS];

        if (characterInT != expectedCharacterInT) {
          return false;
        }
      }

      return true;
    }
};
