class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int n=N%14;
        if(n==0)
            n=14;
        vector<int> v(8,0);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<7;j++)
            {
                v[j]=!(cells[j-1]^cells[j+1]);
            }
            cells=v;
        }
        return v;
    }
};
