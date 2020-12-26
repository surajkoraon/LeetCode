class Solution {
public:
    int numDecodings(string s) {
        int m=s.size();
        vector<int> dp(m+1,0);
        dp[0]=1;
        s[0]=='0'?dp[1]=0:dp[1]=1;
        for(int i=2;i<=m;i++)
        {
            int j=i-1;
            if(s[j]!='0')
                dp[i]+=dp[i-1];
            if((s[j-1]=='2' && s[j]<='6') || (s[j-1]<'2' && s[j-1]>'0'))
                dp[i]+=dp[i-2];
        }
        return dp[m];
    }
};
