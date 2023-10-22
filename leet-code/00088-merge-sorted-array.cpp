class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      vector<int> sortedList;

      int nums1Index = 0;
      int nums2Index = 0;

      while (nums1Index < m && nums2Index < n) {
        const int num1 = nums1[nums1Index];
        const int num2 = nums2[nums2Index];

        if (num1 < num2) {
          sortedList.push_back(num1);
          nums1Index += 1;
        } else {
          sortedList.push_back(num2);
          nums2Index += 1;
        }
      }

      if (nums1Index < m) {
        sortedList.insert(
          sortedList.end(),
          nums1.begin() + nums1Index,
          nums1.begin() + m
        );
      } else if (nums2Index < n) {
        sortedList.insert(
          sortedList.end(),
          nums2.begin() + nums2Index,
          nums2.begin() + n
        );
      }

      nums1 = sortedList;
    }
};
