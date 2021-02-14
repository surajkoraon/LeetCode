class Solution {
public:
    int k=0;
    bool valid(int row,int col,int n)
    {
        if(row<n && col<n && row>=0 && col>=0)
            return true;
        return false;
    }
    int BFS(vector<vector<int>>& grid)
    {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=2;
        while(!q.empty())
        {
            int size=q.size();
            k++;
            for(int i=0;i<size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                if(row==n-1 && col==n-1)
                    return k;
                q.pop();
                if(valid(row-1,col,n) && grid[row-1][col]==0)
                {
                    q.push({row-1,col});
                    grid[row-1][col]=2;
                }
                if(valid(row+1,col,n) && grid[row+1][col]==0)
                {
                    q.push({row+1,col});
                    grid[row+1][col]=2;
                }
                if(valid(row,col-1,n) && grid[row][col-1]==0)
                {
                    q.push({row,col-1});
                    grid[row][col-1]=2;
                }
                if(valid(row,col+1,n) && grid[row][col+1]==0)
                {
                    q.push({row,col+1});
                    grid[row][col+1]=2;
                }
                if(valid(row-1,col-1,n) && grid[row-1][col-1]==0)
                {
                    q.push({row-1,col-1});
                    grid[row-1][col-1]=2;
                }
                if(valid(row+1,col+1,n) && grid[row+1][col+1]==0)
                {
                    q.push({row+1,col+1});
                    grid[row+1][col+1]=2;
                }
                if(valid(row-1,col+1,n) && grid[row-1][col+1]==0)
                {
                    q.push({row-1,col+1});
                    grid[row-1][col+1]=2;
                }
                if(valid(row+1,col-1,n) && grid[row+1][col-1]==0)
                {
                    q.push({row+1,col-1});
                    grid[row+1][col-1]=2;
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return BFS(grid);
    }
};