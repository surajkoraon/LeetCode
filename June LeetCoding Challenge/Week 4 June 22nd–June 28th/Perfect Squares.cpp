class Solution {
public:
    int numSquares(int n) {
        int size=floor(sqrt(n))+1;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=i*i;
        }
        int table[n+1][size];
        for(int j=0;j<size;j++)
        {
            for(int i=0;i<n+1;i++)
            {
                if(i==0||j==0)
                    table[i][j]=0;
                else
                    table[i][j]=INT_MAX;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<size;j++)
            {
                int x;
                if(i-arr[j]<0)
                {
                    x=table[i][j-1];
                }
                else
                {
                    x=table[i-arr[j]][j]+1;
                    if(j>1)
                        x=min(x,table[i][j-1]);
                }
                table[i][j]=min(x,table[i][j]);
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<size;i++)
            ans=min(ans,table[n][i]);
        return ans;
    }
};
