class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        multiset<int> m;
        m.insert(0);
        vector<pair<int,int>> line;
        for(vector<int> tmp:buildings)
        {
            line.push_back({tmp[0],-tmp[2]});
            line.push_back({tmp[1],tmp[2]});
        }
        sort(line.begin(),line.end());
        int max=0;
        for(pair<int,int> p:line)
        {
            if(p.second<0)
                m.insert(-p.second);
            else
                m.erase(m.find(p.second));
            int currentMax=*(m.rbegin());
            if(max!=currentMax)
            {
                v.push_back({p.first,currentMax});
                max=currentMax;
            }
        }
        return v;
    }
};
