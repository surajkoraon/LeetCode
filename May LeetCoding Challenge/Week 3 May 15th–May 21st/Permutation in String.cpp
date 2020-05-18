class Solution {
public:
    bool matched(int arr[])
    {
        for(int i=0;i<26;i++)
            if(arr[i]!=0)
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        if(m>n)
            return false;
        int alpha[26]={0};
        for(int i=0;i<m;i++)
        {
            alpha[s1[i]-'a']--;
            alpha[s2[i]-'a']++;
        }
        for(int i=m;i<n;i++)
        {
            if(matched(alpha))
                return true;
            alpha[s2[i]-'a']++;
            alpha[s2[i-m]-'a']--;
        }
        if(matched(alpha))
            return true;
        return false;
    }
};
