class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int n=s.length();
        int character[128]={0};
        for(int i=0;i<n;i++)
        {
            character[s[i]-'\0']++;
            character[t[i]-'\0']--;
        }
        for(int i=0;i<128;i++)
        {
            if(character[i]!=0)
                return false;
        }
        return true;
    }
};