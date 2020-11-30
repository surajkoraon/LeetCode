class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for(int i=n;i>0;i--)
        {
            int remaining=i-1;
            if(k-remaining>=26)
            {
                s+='z';
                k-=26;
            }
            else
            {
                s+='a'+k-remaining-1;
                k=remaining;
            }
        }
        for(int i=0;i<n/2;i++)
        {
            char ch=s[i];
            s[i]=s[n-1-i];
            s[n-i-1]=ch;
        }
        return s;
    }
};
