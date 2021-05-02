class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long,long> v;
        for(int i=0;i<wall.size();i++)
        {
            int temp=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                temp+=wall[i][j];
                v[temp]++;
            }
        }
        int ans=0;
        for(auto i=v.begin();i!=v.end();i++)
        {
            if(i->second>ans)
                ans=i->second;
        }
        return wall.size()-ans;
    }
};
