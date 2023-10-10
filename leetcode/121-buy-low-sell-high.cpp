class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int maximumProfit = 0;

      int startingPriceIndex = 0;

      for (int i = 1; i < prices.size(); ++i) {
        const int startingPrice = prices[startingPriceIndex];
        const int currentPrice = prices[i];

        if (currentPrice > startingPrice) {
          const int profit = currentPrice - startingPrice;
          maximumProfit = max(maximumProfit, profit);
        } else {
          startingPriceIndex = i;
        }
      }

      return maximumProfit;
    }
};
