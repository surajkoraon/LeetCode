class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size()==0)
            return 1;
        int m=dungeon.size();
        int n=dungeon[0].size();
        int dp[m][n];
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    dp[i][j]=dungeon[i][j];
                }
                else if(i==m-1)
                {
                    dp[i][j]=min(dungeon[i][j],dungeon[i][j]+dp[i][j+1]);
                }
                else if(j==n-1)
                {
                    dp[i][j]=min(dungeon[i][j],dungeon[i][j]+dp[i+1][j]);
                }
                else
                {
                    dp[i][j]=min(dungeon[i][j],dungeon[i][j]+max(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        return max(-dp[0][0]+1,1);
    }
};
