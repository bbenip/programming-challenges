class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      const bool isRotatedArrayIdentical = k % nums.size() == 0;

      if (isRotatedArrayIdentical) {
        return;
      }

      int elementsRotated = 0;

      for (int i = 0; i < nums.size(); ++i) {
        if (elementsRotated == nums.size()) {
          return;
        }

        int numberInTransit = nums[i];

        int slowIndex = (i + k) % nums.size();
        int fastIndex = (i + (2 * k)) % nums.size();

        while (slowIndex != fastIndex) {
          const int nextNumberInTransit = nums[slowIndex];

          nums[slowIndex] = numberInTransit;
          elementsRotated += 1;

          numberInTransit = nextNumberInTransit;

          slowIndex = (slowIndex + k) % nums.size();
          fastIndex = (fastIndex + (2 * k)) % nums.size();
        }

        nums[slowIndex] = numberInTransit;
        elementsRotated += 1;
      }
    }
};
