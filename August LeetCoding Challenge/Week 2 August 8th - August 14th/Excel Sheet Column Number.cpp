class Solution {
public:
    int titleToNumber(string s) {
        int n=s.size()-1;
        int a=0;
        for(int i=n;i>=0;i--)
        {
            a+=pow(26,n-i)*(s[i]-'A'+1);
        }
        return a;
    }
};
