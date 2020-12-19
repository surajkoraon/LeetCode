class Solution {
public:
    bool isValid(int col1,int col2,int col)
    {
        return (col1>=0 && col2>=0 && col1<col && col2<col);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int col1=0,col2=n-1;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        int dir[]={-1,0,1};
        dp[0][col1][col2]=grid[0][col1]+grid[0][col2];
        int maximum=0;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    int prev=dp[i-1][j][k];
                    if(prev>=0)
                    {
                        for(int x:dir)
                        {
                            col1=j+x;
                            for(int y:dir)
                            {
                                col2=k+y;
                                if(isValid(col1,col2,n))
                                {
                                    dp[i][col1][col2]=max(dp[i][col1][col2],prev+(col1==col2?grid[i][col1]:grid[i][col1]+grid[i][col2]));
                                    maximum=max(maximum,dp[i][col1][col2]);
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        return maximum;
    }
};
