class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a,b,i=0,j=0;;
        int m=A.size();
        int n=B.size();
        vector<vector<int>> sol;
        while(i<m && j<n)
        {
            a=max(A[i][0],B[j][0]);
            b=min(A[i][1],B[j][1]);
            vector<int> temp;
            if(a<=b)
            {
                temp.push_back(a);
                temp.push_back(b);
                sol.push_back(temp);            
            }
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        return sol;
    }
};
