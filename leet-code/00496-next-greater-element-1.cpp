class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, int> elementToNextGreaterElement;

      stack<int> decreasingElements;

      for (const auto& num : nums2) {
        while (!decreasingElements.empty() && decreasingElements.top() < num) {
          const int element = decreasingElements.top();
          elementToNextGreaterElement[element] = num;

          decreasingElements.pop();
        }

        decreasingElements.push(num);
      }

      while (!decreasingElements.empty()) {
        const int element = decreasingElements.top();
        elementToNextGreaterElement[element] = -1;

        decreasingElements.pop();
      }

      vector<int> result;

      for (const auto& num : nums1) {
        const int nextGreaterElement = elementToNextGreaterElement[num];

        result.push_back(nextGreaterElement);
      }

      return result;
    }
};
