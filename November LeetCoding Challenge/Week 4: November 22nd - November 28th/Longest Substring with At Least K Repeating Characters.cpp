class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s,0,s.size(),k);
    }
    int helper(string s,int start,int end,int k)
    {
        if(k>(end-start) || start>=end)
            return 0;
        vector<int> frequency(26,0);
        for(int i=start;i<end;i++)
        {
            frequency[s[i]-'a']++;
        }
        int mid;
        for(int i=start;i<end;i++)
        {
            if(frequency[s[i]-'a']<k)
            {
                mid=i+1;
                while(mid<end && frequency[s[mid]-'a']<k)
                    mid++;
                return max(helper(s,start,i,k),helper(s,mid,end,k));
            }
        }
        return end-start;
    }
};
