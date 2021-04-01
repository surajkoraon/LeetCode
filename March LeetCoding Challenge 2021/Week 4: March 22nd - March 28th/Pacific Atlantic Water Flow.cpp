class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        visited[i][j] = true;
        if(i-1>=0 && visited[i-1][j]!=true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix,visited,i-1,j);
        if(i+1<m && visited[i+1][j]!=true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix,visited,i+1,j);
        if(j-1>=0 && visited[i][j-1]!=true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix,visited,i,j-1);
        if(j+1<n && visited[i][j+1]!=true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix,visited,i,j+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0)
            return {};
        int n=matrix[0].size();
        if (n==0)
            return {};
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for(int i=0;i<m;i++) 
        {
            dfs(matrix,pacific,i,0);
            dfs(matrix,atlantic,i,n-1);
        }
        for(int j=0;j<n;j++) 
        {
            dfs(matrix,pacific,0,j);
            dfs(matrix,atlantic,m-1,j);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
