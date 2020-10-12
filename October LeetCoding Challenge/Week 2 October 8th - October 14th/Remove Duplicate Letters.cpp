class Solution {
public:
    string removeDuplicateLetters(string s) {
        string t;
        int remaining[26]={0};
        int used[26]={0};
        for(char ch:s)
            remaining[ch-'a']++;
        for(char ch:s)
        {
            remaining[ch-'a']--;
            if(used[ch-'a']++>0)
                continue;
            while(t.size()!=0 && t.back()>ch && remaining[t.back()-'a']>0)
            {
                used[t.back()-'a']=0;
                t.pop_back();
            }
            t+=ch;
        }
        return t;
    }
};
