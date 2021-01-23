class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> v(m+n-1);
        int index=0;
        for(int i=m-1;i>=0;i--)
        {
            int a=i,b=0;
            while(a<m && b<n)
            {
                v[index].push_back(mat[a++][b++]);
            }
            sort(v[index].begin(),v[index].end());
            index++;
        }
        for(int i=1;i<n;i++)
        {
            int a=0,b=i;
            while(a<m && b<n)
            {
                v[index].push_back(mat[a++][b++]);
            }
            sort(v[index].begin(),v[index].end());
            index++;
        }
        index=0;
        for(int i=m-1;i>=0;i--)
        {
            int a=i,b=0,j=0;
            while(a<m && b<n)
            {
                mat[a++][b++]=v[index][j++];
            }
            index++;
        }
        for(int i=1;i<n;i++)
        {
            int a=0,b=i,j=0;
            while(a<m && b<n)
            {
                mat[a++][b++]=v[index][j++];
            }
            index++;
        }
        return mat;
    }
};
