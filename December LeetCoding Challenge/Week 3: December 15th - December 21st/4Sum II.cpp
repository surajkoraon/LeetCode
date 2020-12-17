class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int arr[A.size()*B.size()];
        int index=0;
        unordered_map<int,int> m;
        int count=0;
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                arr[index++]=A[i]+B[j];
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                m[C[i]+D[j]]++;
        for(int i=0;i<index;i++)
            if(m.count(0-arr[i])>0)
                count+=m[0-arr[i]];
        return count;
    }
};
