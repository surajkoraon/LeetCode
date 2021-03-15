class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long mod = 1000000007;
        sort(arr.begin(), arr.end());
        vector<long> dp(arr.size());
        
        int result = 0;
        for (int i = 0; i < dp.size(); ++i) 
        {
            dp[i] = 1;
            int begin = 0;
            int end = i-1;
            while (begin <= end) 
            {
                long temp=long(arr[begin])*long(arr[end]);
                if (temp > arr[i]) 
                {
                    end--;
                } 
                else if (temp < arr[i]) 
                {
                    begin++;
                } 
                else 
                {
                    dp[i] = (dp[i] + (dp[begin]*dp[end])*(begin == end ? 1 : 2)) % mod;
                    begin++;
                }
            }
            result  = (result + dp[i]) % mod;
        }
        return result;
    }
};
