class KthLargest {
  private:
    int k;
    priority_queue<int, vector<int>, greater<int>> largestKElements;

  public:
    KthLargest(int k, vector<int>& nums) : k { k } {
      for (const auto& num : nums) {
        largestKElements.push(num);
      }

      for (int i = k; i < nums.size(); ++i) {
        largestKElements.pop();
      }
    }

    int add(int val) {
      largestKElements.push(val);

      if (largestKElements.size() > k) {
        largestKElements.pop();
      }

      return largestKElements.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
