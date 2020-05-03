class Solution {
public:
    int DFS(vector<vector<int>>& grid,int row,int col)
    {
        if(row>=grid.size()||col>=grid[row].size())
            return INT_MAX;
         if(row==grid.size()-1 && col==grid[row].size()-1)
             return grid[row][col];
        return min(DFS(grid,row,col+1),DFS(grid,row+1,col))+grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return DFS(grid,0,0);
    }
};