class Solution {
public:
    int numTrees(int n) {
        long long x=1;
        for(int i=0;i<n;i++)
        {
            x=x*(2*n-i);
            x=x/(i+1);
        }
        return x/(n+1);
    }
};