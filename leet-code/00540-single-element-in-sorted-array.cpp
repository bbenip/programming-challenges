class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      if (nums.size() == 1 || nums[0] != nums[1]) {
        return nums[0];
      }

      if (nums[nums.size() - 1] != nums[nums.size() - 2]) {
        return nums[nums.size() - 1];
      }

      int indexLowerBound = 1;
      int indexUpperBound = nums.size() - 2;

      while (indexLowerBound <= indexUpperBound) {
        // Calculate midpoint index without overflow
        const int candidateIndex = (
          indexLowerBound + (indexUpperBound - indexLowerBound) / 2
        );

        const int candidatePredecessor = nums[candidateIndex - 1];
        const int candidate = nums[candidateIndex];
        const int candidateSuccessor = nums[candidateIndex + 1];

        const bool isCandidateUnique = (
          candidate != candidatePredecessor
          && candidate != candidateSuccessor
        );

        if (isCandidateUnique) {
          return candidate;
        }

        if (
          candidate == candidatePredecessor && candidateIndex % 2 != 0
          || candidate == candidateSuccessor && candidateIndex % 2 == 0
        ) {
          indexLowerBound = candidateIndex + 1;
        } else {
          indexUpperBound = candidateIndex - 1;
        }
      }

      return -1;
    }
};
