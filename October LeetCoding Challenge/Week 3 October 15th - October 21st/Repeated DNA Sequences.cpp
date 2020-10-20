class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        if(s.size()<=10)
            return v;
        unordered_map<string,int> m;
        for(int i=0;i+10<=s.length();i++)
        {
            string t=s.substr(i,10);
            m[t]++;
            if(m[t]==2)
                v.push_back(t);
        }
        return v;
    }
};