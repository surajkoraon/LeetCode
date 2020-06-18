class Solution {
public:
    void dfs(vector<vector<char>>& board,int x,int y)
    {
        int row=board.size();
        int col=board[0].size();
        if(x<0||y<0||x>=row||y>=col||board[x][y]=='1'||board[x][y]=='X')
            return;
        board[x][y]='1';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][col-1]=='O')
                dfs(board,i,col-1);
        }
        for(int i=0;i<col;i++)
        {
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[row-1][i]=='O')
                dfs(board,row-1,i);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {   
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='1')
                    board[i][j]='O';
            }
        }
    }
};
