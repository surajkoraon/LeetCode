class Solution {
public:
    int ans=1;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(envelopes.size(),1);
        for(int i=0;i<envelopes.size();i++)
        {
            for(int j=i+1;j<envelopes.size();j++)
            {
                if(envelopes[j][0]>envelopes[i][0] && envelopes[j][1]>envelopes[i][1])
                {
                    dp[j]=max(dp[j],dp[i]+1);
                    ans=max(ans,dp[j]);
                }
            }
        }
        return ans;
    }
};
