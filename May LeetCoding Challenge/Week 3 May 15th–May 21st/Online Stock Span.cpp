class StockSpanner {
public:
    vector<int> v;
    vector<int> stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(1);
        stock.push_back(price);
        int i=v.size()-1;
        int index=i;
        while(i>0 && stock[i-1]<=stock[index])
        {
            v[index]+=v[i-1];
            i=i-v[i-1];
        }
        return v[index];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
