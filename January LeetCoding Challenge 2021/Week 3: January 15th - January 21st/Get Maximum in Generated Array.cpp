class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)
            return n;
        vector<int> v(n+1);
        v[0]=0;
        v[1]=1;
        int i=0;
        int maxNum=0;
        while(2*++i<=n)
        {
            v[2*i]=v[i];
            maxNum=max(maxNum,v[2*i]);
            if(2*i<n)
            {
                v[2*i+1]=v[i]+v[i+1];
                maxNum=max(maxNum,v[2*i+1]);
            }
        }
        return maxNum;
    }
};
