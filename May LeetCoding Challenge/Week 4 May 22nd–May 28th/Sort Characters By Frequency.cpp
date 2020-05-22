class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        map<int,vector<char>> n;
        for(auto it=m.begin();it!=m.end();it++)
        {
            for(int i=0;i<it->second;i++)
            {
                n[it->second].push_back(it->first);
            }
        }  
        s="";
        for(auto it=n.rbegin();it!=n.rend();it++)
        {
            for(int i=0;i<(it->second).size();i++)
            {
                s+=it->second[i];  
            }    
        } 
        return s;
    }
};