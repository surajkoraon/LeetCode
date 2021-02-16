class Solution {
public:
    vector<string> v;
    void recurse(string s,int index)
    {
        if(index==s.length())
        {
            v.push_back(s);
            return;
        }
        if(!isalpha(s[index]))
        {
            recurse(s,index+1);
            return;
        }
        string str=s;
        str[index]=tolower(str[index]);
        recurse(str,index+1);
        str[index]=toupper(str[index]);
        recurse(str,index+1);
    }
    vector<string> letterCasePermutation(string S) {
        recurse(S,0);
        return v;
    }
};