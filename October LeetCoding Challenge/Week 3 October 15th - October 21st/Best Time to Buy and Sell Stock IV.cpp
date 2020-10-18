class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(2*k>=n)
        {
            int ans=0;
            for(int i=1;i<n;i++)
            {
                if(prices[i]>prices[i-1])
                    ans+=prices[i]-prices[i-1];
            }
            return ans;
        }
        vector<int> sell(k+1,0),buy(k+1,INT_MAX);
        for(int price:prices)
        {
            for(int i=1;i<=k;i++)
            {
                cout<<"i="<<i<<endl;
                buy[i]=min(buy[i],sell[i-1]+price);
                sell[i]=max(sell[i],price-buy[i]);
                cout<<buy[i]<<":"<<sell[i]<<endl;
            }
        }
        return sell[k];
    }
}; 
