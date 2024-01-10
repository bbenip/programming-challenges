class BrowserHistory {
  private:
    int historyIndex = -1;
    vector<string> history;

  public:
    BrowserHistory(string homepage)
      : historyIndex { 0 }, history { homepage } {}

    void visit(string url) {
      history.erase(history.begin() + historyIndex + 1, history.end());
      history.push_back(url);
      historyIndex = history.size() - 1;
    }

    string back(int steps) {
      const int minHistoryIndex = 0;
      historyIndex = max(minHistoryIndex, historyIndex - steps);

      return history[historyIndex];
    }

    string forward(int steps) {
      const int maxHistoryIndex = history.size() - 1;
      historyIndex = min(maxHistoryIndex, historyIndex + steps);

      return history[historyIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
