class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> m;
        unordered_map<string,bool> n;
        stringstream s(str);
        string word;
        int i=0;
        while(s>>word)
        {
            if(i==pattern.length())
                return false;
            char ch=pattern[i];
            if(m.count(ch)>0)
            {
                if(m[ch]!=word)
                    return false;
            }
            else
            {
                if(n.count(word)>0)
                    return false;
                m[pattern[i]]=word;
            }
            n[word]=true;
            i++;
        }
        if(i<pattern.length())
            return false;
        return true;
    }
};
