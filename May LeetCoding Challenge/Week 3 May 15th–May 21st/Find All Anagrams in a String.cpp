class Solution {
public:  
    bool matched(int a[])
    {
        for(int i=0;i<26;i++)
            if(a[i]!=0) 
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int m=s.length();
        int n=p.length();
        if(n>m) 
            return v;
        int alpha[26]={0};
        for(int i=0;i<n;i++)
        {
            alpha[s[i]-'a']++;
            alpha[p[i]-'a']--;
        }
        for(int i=n;i<m;i++)
        {
            if(matched(alpha))
                v.push_back(i - n);
            alpha[s[i]-'a']++;
            alpha[s[i-n]-'a']--;
        }
        if(matched(alpha))
            v.push_back(m - n);
        return v;
    }
};
