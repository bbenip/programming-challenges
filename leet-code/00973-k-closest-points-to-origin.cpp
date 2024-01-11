class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<int, vector<int>>> distanceHeap;

      for (const auto& point : points) {
        const int x = point.front();
        const int y = point.back();

        const int distance = pow(x, 2) + pow(y, 2);

        distanceHeap.push({ distance, point });

        if (distanceHeap.size() > k) {
          distanceHeap.pop();
        }
      }

      vector<vector<int>> closestPoints;

      while (!distanceHeap.empty()) {
        vector<int> point = distanceHeap.top().second;
        closestPoints.push_back(point);

        distanceHeap.pop();
      }

      return closestPoints;
    }
};
