class Solution {
public:
    string getSmallestString(int n, int k) {
        int remaining=26*n;
        string s;
        for(int i=0;i<n;i++)
        {
            remaining-=26;
            if(remaining>=k-1)
            {
                s+='a';
                k-=1;
            }
            else
            {
                s+='a'+k-remaining-1;
                k=remaining;
            }
        }
        return s;
    }
};