class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left=0,right=0;
        for(int i=0;i<shift.size();i++)
        {
            if(shift[i][0]==0)
                left-=shift[i][1];
            else
                right+=shift[i][1];
        }
        int x=right+left;
        string a,b;
        if(x>0)
        {
            x=x%s.length();
            int y=s.length()-x;
            for(int i=y;i<s.length();i++)
            {
                a=a+s[i];
            }
            for(int i=0;i<y;i++)
            {
                b=b+s[i];
            }
            return a+b;
        }
        if(x<0)
        {
            x=x*(-1);
            x=x%s.length();
            for(int i=0;i<x;i++)
            {
                a=a+s[i];
            }
            for(int i=x;i<s.length();i++)
            {
                b=b+s[i];
            }
            return b+a;
        }
        return s;
    }
};