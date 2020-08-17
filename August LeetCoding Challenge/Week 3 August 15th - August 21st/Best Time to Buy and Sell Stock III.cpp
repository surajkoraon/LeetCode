class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        int buy1=-prices[0],buy2=INT_MIN,sell1=INT_MIN,sell2=INT_MIN;
        for(int i=1;i<n;i++)
        {
            buy1=max(buy1,-prices[i]);
            sell1=max(sell1,buy1+prices[i]);
            buy2=max(buy2,sell1-prices[i]);
            sell2=max(sell2,buy2+prices[i]);
        }
        return max(0,sell2);
    }
};
