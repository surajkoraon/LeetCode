class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;
        vector<int> sol;
        for(int i=0;i<intervals.size();i++)
        {
            v.push_back({intervals[i][0],i});
        }
        sort(v.begin(),v.end());
        for(vector<int> temp:intervals)
        {
            int a=temp[1];
            int index=lower_bound(v.begin(),v.end(),make_pair(a,0))-v.begin();
            if(index==v.size())
                sol.push_back(-1);
            else
                sol.push_back(v[index].second);
        }
        return sol;
    }
};
