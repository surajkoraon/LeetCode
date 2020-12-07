class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1;
        int left = 0;
        int right = n-1;
        int top = 0;
        int down = n-1;
        vector<vector<int>> v(n,vector<int>(n));
        while(val<=n*n)
        {
            for(int i=left;i<=right;i++)
                v[top][i]=val++;
            top++;
            for(int i=top;i<=down;i++)
                v[i][right]=val++;
            right--;
            for(int i=right;i>=left;i--)
                v[down][i]=val++;
            down--;
            for(int i=down;i>=top;i--)
                v[i][left]=val++;
            left++;
        }
        return v;
    }
};
