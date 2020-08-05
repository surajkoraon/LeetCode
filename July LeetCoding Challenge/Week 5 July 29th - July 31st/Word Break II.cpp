class Solution {
public:
    unordered_map<string,vector<string>> dp;
    vector<string> recurse(string s, vector<string>& wordDict)
    {
        if(s=="")
            return {""};
        if(dp.find(s)!=dp.end())
            return dp[s];
        vector<string> a,b;
        for(string word:wordDict)
        {
            string temp=s.substr(0,word.size());
            if(temp!=word)
                continue;
            a=recurse(s.substr(word.size()),wordDict);
            for(string ans:a)
            {
                string space=ans.size()==0?"":" ";
                b.push_back(word+space+ans);
            }
        }
        dp[s]=b;
        return b;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sol=recurse(s,wordDict);
        return sol;
    }
};