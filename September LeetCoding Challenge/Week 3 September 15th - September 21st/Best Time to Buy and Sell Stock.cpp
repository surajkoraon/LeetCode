class Solution {
public:
    int sol;
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        for(int i:prices)
        {
            sol=max(sol,i-buy);
            buy=min(buy,i);
        }
        return sol;
    }
};
