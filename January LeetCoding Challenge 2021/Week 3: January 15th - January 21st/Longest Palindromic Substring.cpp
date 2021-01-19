class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int start=0,end=0;
        for(int i=0;i<s.length();i++)
        {
            int len1=expandThroughMiddle(s,i,i);
            int len2=expandThroughMiddle(s,i,i+1);
            int len=max(len1,len2);
            if(len>end-start+1)
            {
                start=i-(len-1)/2;
                end=i+(len/2);
            }
        }
        return s.substr(start,end-start+1);
    }
    int expandThroughMiddle(string s,int left,int right)
    {
        if(s.size()==0 || left>right)
            return 0;
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
};
