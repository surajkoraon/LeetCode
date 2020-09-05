class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string s,temp;
        sort(A.begin(),A.end());
        do
        {
            if((A[0]==2 && A[1]<4 || A[0]<2) && A[2]<6)
            {
                s=to_string(A[0])+to_string(A[1])+":"+to_string(A[2])+to_string(A[3]);
                temp=max(temp,s);
            }
        }while(next_permutation(A.begin(),A.end()));
        return temp;
    }
};