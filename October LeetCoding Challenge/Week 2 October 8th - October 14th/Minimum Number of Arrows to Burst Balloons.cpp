class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=1)
            return n;
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b)
             {
                 return a[1]<b[1];
             });
        int count=0;
        int arrow=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arrow>=points[i][0])
                continue;
            else
            {
                arrow=points[i][1];
                count++;
            }
        }
        return count;
    }
};
