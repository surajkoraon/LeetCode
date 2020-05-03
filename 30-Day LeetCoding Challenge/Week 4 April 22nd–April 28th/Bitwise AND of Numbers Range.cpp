class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n)
            return n;
        if(m==0)
            return 0;
        if((n-1) & 2147483647 == n-1)
            return 0;
        if((m-1) && 2147483647 == m-1)
            return m;
        int sol=n;
        for(int i=ceil(log2(n));i>0;i--)
        {
            if(m<1<<i && n>1<<i)
            {
                return 0;
            }
        }
        for(int i=m;i<n;i++)
        {
            sol=sol&i;
        }
        return sol;
    }
};