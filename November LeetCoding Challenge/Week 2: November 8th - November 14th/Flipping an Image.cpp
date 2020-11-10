class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        for(int i=0;i<m;i++)
        {
            int x=0,y=n-1;
            while(x<=y)
            {
                if(A[i][x]==A[i][y])
                {
                    A[i][x]=!A[i][x];
                    if(x!=y)
                        A[i][y]=!A[i][y];
                }
                x++;
                y--;
            }
        }
        return A;
    }
};
