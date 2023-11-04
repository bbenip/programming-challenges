class MinStack {
  private:
    stack<int> values;
    vector<int> minimumValues;

  public:
    MinStack() {}

    void push(int val) {
      values.push(val);

      const int minimumValue = min(
        minimumValues.empty() ? INT_MAX : minimumValues.back(),
        val
      );

      minimumValues.push_back(minimumValue);
    }

    void pop() {
      values.pop();
      minimumValues.pop_back();
    }

    int top() {
      return values.top();
    }

    int getMin() {
      return minimumValues.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
