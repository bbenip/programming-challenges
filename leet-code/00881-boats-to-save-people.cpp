class Solution {
  public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(), people.end());

      int index1 = 0;
      int index2 = people.size() - 1;

      int minBoatsRequired = 0;

      while (index1 <= index2) {
        minBoatsRequired += 1;

        const int smallestWeight = people[index1];
        const int largestWeight = people[index2];

        int weightOnBoat = largestWeight;
        index2 -= 1;

        const bool isAnyPersonLeft = index1 <= index2;
        const bool isRoomForSmallestWeight = (
          limit - weightOnBoat >= smallestWeight
        );

        if (isAnyPersonLeft && isRoomForSmallestWeight) {
          index1 += 1;
        }
      }

      return minBoatsRequired;
    }
};
