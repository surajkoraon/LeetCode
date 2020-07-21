class Solution {
public:
    bool dfs(int row,int col,vector<vector<char>> &board,vector<vector<bool>> &v,string word)
    {
        if(word=="")
            return true;
        int m=board.size();
        int n=board[0].size();
        if(row<0 || row>=m || col<0 || col>=n)
        {
            return false;
        }
        if(v[row][col]==true)
        {
            return false;
        }
        if(word[0]!=board[row][col])
        {
            return false;
        }
        v[row][col]=true;
        word=word.substr(1,word.size()-1);
        bool result=dfs(row+1,col,board,v,word) || dfs(row-1,col,board,v,word) || dfs(row,col+1,board,v,word) || dfs(row,col-1,board,v,word);
        v[row][col]=false;
        return result;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char,int> m;
        unordered_map<char,int> n;
        vector<vector<bool>> v(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                m[board[i][j]]++;
            }   
        }
        for(char ch:word)
        {
            n[ch]++;
        }
        for(auto it=n.begin();it!=n.end();it++)
        {
            if(it->second>m[it->first])
                return false;
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,board,v,word))
                        return true;
                }
            }
        }
        return false;
    }
};
