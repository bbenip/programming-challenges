class MyStack {
  private:
    queue<int> elements;

  public:
    MyStack() {}

    void push(int x) {
      queue<int> updatedElements;

      updatedElements.push(x);

      while (!elements.empty()) {
        const int currentElement = elements.front();
        updatedElements.push(currentElement);

        elements.pop();
      }

      elements = updatedElements;
    }

    int pop() {
      const int element = elements.front();
      elements.pop();

      return element;
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
