class Solution {
  public:
    int maxNumberOfBalloons(string text) {
      unordered_map<char, int> characterFrequency;
      unordered_map<char, int> balloonCharacterFrequency;

      string balloon = "balloon";

      for (const auto& ch : balloon) {
        balloonCharacterFrequency[ch] += 1;
      }

      for (const auto& ch : text) {
        const bool isCharacterInBalloon = (
          balloonCharacterFrequency.contains(ch)
        );

        if (isCharacterInBalloon) {
          characterFrequency[ch] += 1;
        }
      }

      int numberOfBalloons = text.size();

      for (
        const auto& [balloonCharacter, expectedFrequency]
        : balloonCharacterFrequency
      ) {
        const int frequency = characterFrequency[balloonCharacter];
        const int numberOfBalloonsForCharacter = frequency / expectedFrequency;

        numberOfBalloons = min(numberOfBalloons, numberOfBalloonsForCharacter);
      }

      return numberOfBalloons;
    }
};
