class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int maximum=0;
        int max_so_far=0;
        int start=0;
        for(int i=0;i<s.length();i++)
        {
            if(m.count(s[i])==0 || m[s[i]]<start)
            {
                m[s[i]]=i;
                max_so_far++;
                maximum=max(maximum,max_so_far);
            }
            else
            {
                start=m[s[i]]+1;
                max_so_far=i-m[s[i]];
                m[s[i]]=i;
            }
        }
        return maximum;
    }
};
