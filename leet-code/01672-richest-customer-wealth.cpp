class Solution {
  public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int maximumCustomerWealth = 0;

      for (const auto& customerAccounts : accounts) {
        int customerWealth = 0;

        for (const auto& amount : customerAccounts) {
          customerWealth += amount;
        }

        maximumCustomerWealth = max(maximumCustomerWealth, customerWealth);
      }

      return maximumCustomerWealth;
    }
};
