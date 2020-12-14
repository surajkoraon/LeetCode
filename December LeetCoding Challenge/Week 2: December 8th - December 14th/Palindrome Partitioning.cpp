class Solution {
public:
    void pallindrome(string& s,unordered_map<string,bool>& m)
    {
        int n=s.size();
        for(int i=0;i<n/2;i++)
            if(s[i]!=s[n-i-1])
            {
                m[s]=false;
                return;
            }
        m[s]=true;
    }
    void helper(string& s,int index,unordered_map<string,bool>& m,vector<vector<string>>& v,vector<string>& temp)
    {
        int n=s.size();
        if(n==index)
        {
            v.push_back(temp);
            return;
        }
        string t;
        for(int i=index;i<n;i++)
        {
            t+=s[i];
            if(m.count(t)==0)
                pallindrome(t,m);
            if(m[t])
            {
                temp.push_back(t);
                helper(s,i+1,m,v,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        unordered_map<string,bool> m;
        vector<vector<string>> v;
        vector<string> temp;
        helper(s,0,m,v,temp);
        return v;
    }
};
