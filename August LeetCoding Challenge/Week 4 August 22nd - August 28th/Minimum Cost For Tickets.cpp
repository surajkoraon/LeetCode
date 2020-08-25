class Solution {
public:
    map<vector<int>::iterator,int> m;
    int recurse(vector<int>::iterator it,vector<int>& days, vector<int>& costs,int price)
    {
        if(it==days.end())
        {
            return 0;
        }
        if(m.count(it)>0)
            return m[it];
        int x=recurse(lower_bound(it,days.end(),*it+1),days,costs,price)+costs[0];
        int y=recurse(lower_bound(it,days.end(),*it+7),days,costs,price)+costs[1];
        int z=recurse(lower_bound(it,days.end(),*it+30),days,costs,price)+costs[2];
        int mincost=min(min(x,y),z);
        m[it]=mincost;
        return mincost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int mincost=recurse(days.begin(),days,costs,0);
        return mincost;
    }
};
