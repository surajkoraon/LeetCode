class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        int sum=0;
        int i=1;
        int prev=A[1]-A[0];
        int start=0;
        while(++i<n)
        {
            if(A[i]-A[i-1]==prev)
            {
                sum+=i-start-1;
            }
            else
            {
                prev=A[i]-A[i-1];
                start=i-1;
            }
        }
        return sum;
    }
};