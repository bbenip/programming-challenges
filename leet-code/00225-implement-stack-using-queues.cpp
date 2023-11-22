class MyStack {
  private:
    queue<int> elements;

  public:
    MyStack() {}

    void push(int x) {
      const int size = elements.size();

      elements.push(x);

      for (int i = 0; i < size; ++i) {
        const int element = elements.front();
        elements.pop();
        elements.push(element);
      }
    }

    int pop() {
      const int poppedElement = elements.front();
      elements.pop();

      return poppedElement;
    }

    int top() {
      return elements.front();
    }

    bool empty() {
      return elements.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
