class StockSpanner {
  private:
    stack<pair<int, int>> nonIncreasingStockPricesWithSpan;

  public:
    StockSpanner() {}

    int next(int price) {
      int span = 1;

      while (
        !nonIncreasingStockPricesWithSpan.empty()
        && nonIncreasingStockPricesWithSpan.top().first <= price
      ) {
        span += nonIncreasingStockPricesWithSpan.top().second;
        nonIncreasingStockPricesWithSpan.pop();
      }

      nonIncreasingStockPricesWithSpan.push({ price, span });

      return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
