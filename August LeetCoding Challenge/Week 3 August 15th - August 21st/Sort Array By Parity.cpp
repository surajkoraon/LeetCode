class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size()<=1)
            return A;
        int left=0,right=A.size()-1;
        while(1)
        {
            while(!(A[left]&1) && left+1!=A.size())
                left++;
            while((A[right]&1) && right-1!=-1)
                right--;
            if(left>=right)
                return A;
            swap(A[left],A[right]);
        }
        return A;
    }
};
