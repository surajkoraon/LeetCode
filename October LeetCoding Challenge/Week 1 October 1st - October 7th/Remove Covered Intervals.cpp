class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int sol=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[&](vector<int> a,vector<int> b)
             {
                 return (a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]));
             });
        vector<int> temp=intervals[0];
        for(int i=1;i<n;i++)
        {
            if(temp[1]>=intervals[i][1])
                sol++;
            else
                temp=intervals[i];
        }
        return n-sol;
    }
};
