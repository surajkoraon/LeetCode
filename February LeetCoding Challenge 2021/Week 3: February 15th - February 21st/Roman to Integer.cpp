class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int n=s.length();
        int prev=m[s[n-1]];
        int num=0;
        for(int i=n-1;i>=0;i--)
        {
            if(m[s[i]]<prev)
            {
                num-=m[s[i]];
            }
            else
            {
                num+=m[s[i]];
            }
            prev=m[s[i]];
        }
        return num;
    }
};