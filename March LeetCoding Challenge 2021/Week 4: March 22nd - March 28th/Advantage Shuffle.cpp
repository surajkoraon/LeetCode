class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        if(n < 2 ) return A;
    
        sort(A.begin(), A.end());
        vector<pair<int,int>> C;
        for(int i=0; i<n; ++i)
            C.push_back( make_pair(B[i], i));    
        sort(C.begin(), C.end());
       
        int l = 0, r = n-1;
        vector<int> D(n); 
        for(int i = n-1; i >=0; i--){
           if(A[r]<=C[i].first)
                D[C[i].second] = A[l++];
            else
                D[C[i].second] = A[r--];       
        }   
        return D;
    }
};
