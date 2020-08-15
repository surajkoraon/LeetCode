
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        int n=interval.size();
        if(n<=1)
            return 0;
        int ans=0;
        sort(interval.begin(),interval.end(),[](vector<int> &a,vector<int> &b)
             {
                return a[1]<b[1]; 
             });
        int end=interval[0][1];
        for(int i=1;i<n;i++)
        {
            if(interval[i][0]<end)
                ans++;
            else
                end=interval[i][1];
        }
        return ans;
    }
};