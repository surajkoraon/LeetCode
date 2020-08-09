class Solution {
public:
    int count=0;
    void dfs(vector<vector<int>> grid,int i,int j,int m,int n,int total,vector<vector<int>>& v)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(grid[i][j]==1)
        {
            grid[i][j]=2;
            total++;
            v[i][j]=min(v[i][j],total);
            dfs(grid,i+1,j,m,n,total,v);
            dfs(grid,i,j+1,m,n,total,v);
            dfs(grid,i-1,j,m,n,total,v);
            dfs(grid,i,j-1,m,n,total,v);
        }
        else
        {
            return;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> v(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    v[i][j]=0;
                if(grid[i][j]==2)
                {
                    v[i][j]=0;
                    dfs(grid,i+1,j,m,n,0,v);
                    dfs(grid,i,j+1,m,n,0,v);
                    dfs(grid,i-1,j,m,n,0,v);
                    dfs(grid,i,j-1,m,n,0,v);
                }
            }
        }
        cout<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==INT_MAX)
                    return -1;
                count=max(count,v[i][j]);
            }
            cout<<endl;
        }
        return count;
    }
};