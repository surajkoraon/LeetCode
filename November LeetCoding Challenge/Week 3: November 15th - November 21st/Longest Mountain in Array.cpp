class Solution {
public:
    bool isIncreasingSubsequence=false;
    bool isDecreasingSubsequence=false;
    int count=0;
    int prev=0;
    int i;
    int longestMountain(vector<int>& A) {
        for(i=1;i<A.size();i++)
        {
            if(!isIncreasingSubsequence)
            {
                if(A[i-1]<A[i])
                    isIncreasingSubsequence=true;
                else
                    prev=i;
            }
            else if(isDecreasingSubsequence)
            {
                if(A[i-1]<A[i])
                {
                    isDecreasingSubsequence=false;
                    count=max(count,i-prev);
                    prev=i-1;
                }
                else if(A[i-1]==A[i])
                {
                    isIncreasingSubsequence=false;
                    isDecreasingSubsequence=false;
                    count=max(count,i-prev);
                    prev=i;
                }
            }
            else if(isIncreasingSubsequence)
            {
                if(A[i-1]>A[i])
                    isDecreasingSubsequence=true;
                else if(A[i-1]==A[i])
                {
                    isIncreasingSubsequence=false;
                    isDecreasingSubsequence=false;
                    prev=i;
                }
            }
        }
        if(isDecreasingSubsequence)
            count=max(count,i-prev);
        return count;
    }
};
