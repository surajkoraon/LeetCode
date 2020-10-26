class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(query_row+1,vector<double>(query_row+1,0));
        v[0][0]=poured;
        for(int i=0;i<=query_row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(v[i][j]>1 && i+1<=query_row)
                {
                    v[i+1][j]+=(v[i][j]-1)/2;
                    v[i+1][j+1]+=(v[i][j]-1)/2;
                    v[i][j]=1;
                }
            }
        }
        return v[query_row][query_glass]>1?1:v[query_row][query_glass];
    }
};
