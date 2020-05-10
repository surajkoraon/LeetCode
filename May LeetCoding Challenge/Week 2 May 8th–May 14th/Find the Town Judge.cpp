class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0)
            return N;
        unordered_map<int,int> mi;
        unordered_map<int,int> mj;
        for(int i=0;i<trust.size();i++)
        {
            mi[trust[i][0]]++;
            mj[trust[i][1]]++;
        }
        if(mi.size()!=N-1)
            return -1;
        for(auto i=mj.begin();i!=mj.end();i++)
        {
            if(i->second==N-1)
            {
                if(mi.find(i->first)==mi.end())
                    return i->first;
            }
        }
        return -1;
    }
};
