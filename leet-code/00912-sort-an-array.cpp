class Solution {
  private:
    vector<int> collate(const vector<int>& v1, const vector<int>& v2) {
      const int size = v1.size() + v2.size();
      vector<int> collatedArray;

      int index1 = 0;
      int index2 = 0;

      while (index1 < v1.size() && index2 < v2.size()) {
        const int element1 = v1[index1];
        const int element2 = v2[index2];

        if (element1 <= element2) {
          collatedArray.push_back(element1);
          index1 += 1;
        } else {
          collatedArray.push_back(element2);
          index2 += 1;
        }
      }

      if (index1 < v1.size()) {
        collatedArray.insert(
          collatedArray.end(),
          v1.begin() + index1,
          v1.end()
        );
      }

      if (index2 < v2.size()) {
        collatedArray.insert(
          collatedArray.end(),
          v2.begin() + index2,
          v2.end()
        );
      }

      return collatedArray;
    }

  public:
    vector<int> sortArray(vector<int>& nums) {
      if (nums.size() <= 1) {
        return nums;
      }

      vector<int> leftHalfOfArray;

      leftHalfOfArray.insert(
        leftHalfOfArray.end(),
        nums.begin(),
        nums.begin() + nums.size() / 2
      );

      vector<int> sortedLeftHalfOfArray = sortArray(leftHalfOfArray);

      vector<int> rightHalfOfArray;

      rightHalfOfArray.insert(
        rightHalfOfArray.end(),
        nums.begin() + nums.size() / 2,
        nums.end()
      );

      vector<int> sortedRightHalfOfArray = sortArray(rightHalfOfArray);

      vector<int> sortedArray = collate(
        sortedLeftHalfOfArray,
        sortedRightHalfOfArray
      );

      nums = sortedArray;

      return nums;
    }
};
