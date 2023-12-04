class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int lowerBound = 0;
      int upperBound = arr.size() - k;

      while (lowerBound < upperBound) {
        const int index = lowerBound + (upperBound - lowerBound) / 2;

        const int smallestElementInWindow = arr[index];
        const int largestElementInWindow = arr[index + k];

        const int absoluteDifference1 = abs(x - smallestElementInWindow);
        const int absoluteDifference2 = abs(x - largestElementInWindow);

        if (absoluteDifference1 <= absoluteDifference2) {
          upperBound = index;
        } else {
          lowerBound = index + 1;
        }
      }

      if (k != arr.size() && arr[lowerBound] == arr[arr.size() - k - 1]) {
        lowerBound = max(((int) arr.size()) - 2 * k, 0);
      }

      deque<int> candidateElements;

      for (int i = 0; i < 2 * k; ++i) {
        const int index = lowerBound + i;

        if (index >= arr.size()) {
          break;
        }

        const int element = arr[index];
        candidateElements.push_back(element);

        if (candidateElements.size() > k) {
          const int smallestElement = candidateElements.front();
          const int largestElement = candidateElements.back();

          const int absoluteDifference1 = abs(x - smallestElement);
          const int absoluteDifference2 = abs(x - largestElement);

          if (absoluteDifference1 <= absoluteDifference2) {
            candidateElements.pop_back();
          } else {
            candidateElements.pop_front();
          }
        }
      }

      const vector<int> closestElements(
        candidateElements.begin(),
        candidateElements.end()
      );

      return closestElements;
    }
};
