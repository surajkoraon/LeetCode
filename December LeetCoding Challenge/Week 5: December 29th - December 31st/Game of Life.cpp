class Solution {
public:
    bool isvalid(int i,int j,vector<vector<int>>& board,int m,int n)
    {
        if(i>=0 && j>=0 && i<m && j<n)
            return (board[i][j]==1 ||board[i][j]==-1);
        return false;
    }
    int life(int i,int j,vector<vector<int>>& board,int m,int n)
    {
        int count=0;
        int dir[]={-1,0,1};
        for(int row=0;row<3;row++)
        {
            for(int col=0;col<3;col++)
            {
                if(row==1 && col==1);
                else if(isvalid(i+dir[row],j+dir[col],board,m,n))
                    count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=life(i,j,board,m,n);
                if(board[i][j]==0)
                {
                    if(count==3)
                        board[i][j]=-2;     //-1 to keep track of transition from 1 to 0
                }
                else
                {
                    if(count<2 || count>3)
                        board[i][j]=-1;     //-2 to keep track of transition from 0 to 1
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==-1)
                    board[i][j]=0;
                else if(board[i][j]==-2)
                    board[i][j]=1;
            }
        }
    }
};
