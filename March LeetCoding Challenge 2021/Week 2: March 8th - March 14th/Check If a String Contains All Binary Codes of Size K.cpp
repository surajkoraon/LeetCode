class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k)
            return false;
        set<int> st;
        int mask=(1<<k)-1;
        int num=0;
        for(int i=0;i<s.length();i++)
        {
            num=(num<<1) & mask | (s[i]-'0');
            if(i>=k-1)
            {
                st.insert(num);
            }
        }
        return st.size()==1<<k;
    }
};
