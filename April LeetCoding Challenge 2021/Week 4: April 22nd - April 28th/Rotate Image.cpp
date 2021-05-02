class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int c=0;c<n/2;++c) 
        {
            int l=n-1-c;
            for (int i=0;i<l-c;++i) 
            {
                int temp=matrix[c][c+i];
                matrix[c][c+i]=matrix[l-i][c];
                matrix[l-i][c]=matrix[l][l-i];
                matrix[l][l-i]=matrix[c+i][l];
                matrix[c+i][l]=temp;
            }
        }
    }
};
