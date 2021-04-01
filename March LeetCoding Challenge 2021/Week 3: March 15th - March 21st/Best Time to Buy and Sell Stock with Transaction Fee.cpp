class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN; 
        for(int p:prices) {
            s1 = max(s1, s0-p);
            s0 = max(s0, s1+p-fee);
        }
        return s0;
    }
};
