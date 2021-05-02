class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=0,zero=0,one=0;
        char prev=s[0];
        for(int i=0;i<s.length();i++)
        {
            if(prev!=s[i])
            {
                if(s[i]=='0')
                {
                    if(zero>0)
                    {
                        count+=min(zero,one);
                    }
                    zero=1;
                }
                else
                {
                    if(one>0)
                    {
                        count+=min(zero,one);
                    }
                    one=1;
                }
            }
            else
            {
                if(s[i]=='0')
                    zero++;
                else
                    one++;
            }
            prev=s[i];
        }
        count+=min(zero,one);
        return count;
    }
};
