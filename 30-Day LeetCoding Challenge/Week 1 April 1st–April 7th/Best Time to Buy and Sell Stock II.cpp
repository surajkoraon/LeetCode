class Solution {
    

    int INF = 1e9 + 5;
public:
    int maxProfit(vector<int>& prices) {
        int profit_with_stock = -INF, profit_without_stock = 0;
        for(int price : prices) {
            profit_with_stock = max(profit_with_stock, profit_without_stock - price);
            profit_without_stock = max(profit_without_stock, profit_with_stock + price);
        }
        
        return profit_without_stock;
    }
};