class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> v;
        int n=A.size();
        for(int i=n;i>0;i--)
        {
            int j=0;
            while(A[j++]!=i);
            reverse(A.begin(),A.begin()+j);
            reverse(A.begin(),A.begin()+i);
            v.push_back(j);
            v.push_back(i);
        }
        return v;
    }
};