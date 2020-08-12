class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        vector<int> v(n+1,0);
        v[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=i;j>0;j--)
                v[j]=v[j]+v[j-1];
        return v;
    }
};
