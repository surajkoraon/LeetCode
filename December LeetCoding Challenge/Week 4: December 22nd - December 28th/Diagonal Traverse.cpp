class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return {};
        int n=matrix[0].size();
        vector<int> v;
        int i=0,j=0;
        bool flag=true;
        while(i<m && j<n)
        {
            v.push_back(matrix[i][j]);
            if(((i==0 || j==n-1) && (flag)) || ((j==0 || i==m-1) && (!flag)))
            {
                if(flag)
                {
                    if(j==n-1)
                        i++;
                    else
                        j++;
                }
                else
                {
                    if(i==m-1)
                        j++;
                    else
                        i++;
                }
                flag=!flag;
            }
            else
            {
                if(flag)
                {
                    i--;
                    j++;
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return v;
    }
};
