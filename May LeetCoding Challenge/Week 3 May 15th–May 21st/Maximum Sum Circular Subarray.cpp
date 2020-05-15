class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxs=A[0];
        int mins=A[0];
        int maxsofar=A[0];
        int minsofar=A[0];
        int sum=A[0];
        for(int i=1;i<A.size();i++)
        {
            maxs=max(maxs+A[i],A[i]);
            mins=min(mins+A[i],A[i]);
            maxsofar=max(maxs,maxsofar);
            minsofar=min(mins,minsofar);
            sum+=A[i];
        }
        if(minsofar==sum)
            return maxsofar;
        return max(maxsofar,sum-minsofar);
    }
};