class Solution {
public:
    bool isSafe(int i,int j,int row,int col)
    {
        if(i<0 || j<0 || i>=row || j>=col)
            return false;
        return true;
    }
    int perimeterCount(int row,int col,int m,int n,vector<vector<int>>& grid)
    {
        if(!isSafe(row,col,m,n))
            return 1;
        if(grid[row][col]==0)
        {
            grid[row][col]=2;
            return 1;
        }
        if(grid[row][col]==2)
        {
            return 1;
        }
        if(grid[row][col]==3)
        {
            return 0;
        }
        grid[row][col]=3;
        int count = perimeterCount(row-1,col,m,n,grid) + perimeterCount(row+1,col,m,n,grid) + perimeterCount(row,col-1,m,n,grid) + perimeterCount(row,col+1,m,n,grid);
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    count=perimeterCount(i,j,m,n,grid);
                    return count;
                }
            }
        }
        return count;
    }
};
