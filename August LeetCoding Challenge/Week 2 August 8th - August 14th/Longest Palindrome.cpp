class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int count=0;
        int flag=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(flag==0)
                if(it->second%2==1)
                    flag=1;
            if(it->second>1)
            {
                count+=it->second/2;
            }
        }
        return count*2+flag;
    }
};
