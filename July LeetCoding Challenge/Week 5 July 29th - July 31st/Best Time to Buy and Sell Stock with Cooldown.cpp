int fun(vector<int>& prices, int index, int buy, unordered_map<string, int>& hash)
    {
        if(index>=prices.size())
            return 0;
        int x = 0;
        if(hash.count(to_string(index)+ " " +to_string(buy)))
            return hash[to_string(index)+ " " +to_string(buy)];
        if(buy)
        {
            int a = fun(prices, index+1, 1, hash);
            int b = fun(prices, index+1, 0, hash) - prices[index];
            x = max(a, b);
        }
        else
        {
            int a = fun(prices, index+1, 0, hash);
            int b = fun(prices, index+2, 1, hash) + prices[index];
            x = max(a, b);
        }
        hash[to_string(index)+ " " +to_string(buy)] = x;
        return x;
    }
    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> hash;
        return fun(prices, 0, 1, hash);
    }