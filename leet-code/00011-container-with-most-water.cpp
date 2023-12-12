class Solution {
  public:
    int maxArea(vector<int>& heights) {
      int maximumArea = 0;

      int index1 = 0;
      int index2 = heights.size() - 1;

      while (index1 < index2) {
        const int width = index2 - index1;
        const int height = min(heights[index1], heights[index2]);

        const int area = width * height;

        maximumArea = max(maximumArea, area);

        if (heights[index1] < heights[index2]) {
          index1 += 1;
        } else {
          index2 -= 1;
        }
      }

      return maximumArea;
    }
};
