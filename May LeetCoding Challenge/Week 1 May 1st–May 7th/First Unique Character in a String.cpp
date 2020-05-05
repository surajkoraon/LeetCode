class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size()==0)
            return -1;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                m[s[i]]=-1;
            }
            else
                m[s[i]]=i;
        }
        int min_index=INT_MAX;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>=0 && it->second<min_index)
            {
                min_index=it->second;
            }
        }
        if(min_index>=s.size())
            return -1;
        return min_index;
    }
};
