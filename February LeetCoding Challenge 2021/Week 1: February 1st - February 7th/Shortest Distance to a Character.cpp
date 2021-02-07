class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        int i=0,j=-1,prev=-10001;
        vector<int> v(n);
        while(i<n)
        {
            if(s[i]!=c || i==j)
            {
                i++;
            }
            else
            {
                j++;
                v[j]=min(j-prev,i-j);
            }
            if(i==j)
                prev=i;
        }
        if(prev!=n-1)
            for(i=j+1;i<n;i++)
                v[i]=i-prev;
        return v;
    }
};