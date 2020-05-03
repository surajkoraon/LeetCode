class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;        
        if(strs.size() == 0) return v;        
        map<string,vector<string>> m;
        for(string s: strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            m[key].push_back(s);
        }
        map<string,vector<string>>::iterator itr = m.begin();
        while(itr != m.end())
        {
            v.push_back(itr->second);
            itr++;
        }
    
        return v;
    }
};