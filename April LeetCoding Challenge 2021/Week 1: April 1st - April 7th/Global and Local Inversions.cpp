class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return true;
        int temp=A[0];
        for(int i=2;i<n;i++)
        {
            if(A[i]<temp)
                return false;
            temp=max(temp,A[i-1]);
                
        }
        return true;
    }
};
