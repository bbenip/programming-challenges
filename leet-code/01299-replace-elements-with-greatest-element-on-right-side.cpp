class Solution {
  public:
    vector<int> replaceElements(vector<int>& arr) {
      int largestElementToRight = -1;
      int elementToRight = -1;

      for (int i = arr.size() - 1; i >= 0; --i) {
        largestElementToRight = max(largestElementToRight, elementToRight);
        elementToRight = arr[i];

        arr[i] = largestElementToRight;
      }

      return arr;
    }
};
