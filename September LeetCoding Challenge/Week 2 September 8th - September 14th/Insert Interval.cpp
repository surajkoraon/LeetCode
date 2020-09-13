class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if(intervals.size()==0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int a=newInterval[0];
        int b=newInterval[1];
        vector<int> v(2);
        if(a<intervals[0][0] && b<intervals[0][0])
        {
            v[0]=a;
            v[1]=b;
            intervals.push_back(v);
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
        int x=-1,y=-1;
        for(int i=0;i<intervals.size();i++)
        {
            if(a>=intervals[i][0])
            {
                x=i;
            }
            if(b>=intervals[i][0])
            {
                y=i;
            }
        }
        x=max(x,0);
        y=max(y,0);
        b=max(intervals[y][1],b);
        if(a>intervals[x][1])
            x+=1;
        else
            a=min(intervals[x][0],a);
        intervals.erase(intervals.begin()+x,intervals.begin()+y+1);
        v[0]=a;
        v[1]=b;
        intervals.push_back(v);
        sort(intervals.begin(),intervals.end());
        return intervals;
    }
};
