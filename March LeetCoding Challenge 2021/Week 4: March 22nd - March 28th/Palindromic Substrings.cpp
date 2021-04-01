class Solution {
public:
    int count=0;
    void helper(string s,int start,int end)
    {
        count++;
        if(start>0 && end<s.length()-1 && s[start-1]==s[end+1])
        {
            helper(s,start-1,end+1);
        }
        if(start==end && end<s.length()-1 && s[start]==s[end+1])
        {
            helper(s,start,end+1);
        }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++)
            helper(s,i,i);
        return count;
    }
};
