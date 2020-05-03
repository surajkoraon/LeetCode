class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(char c:ransomNote)
        {
            m[c]++;
        }
        for(char c:magazine)
        {
            m[c]--;
        }
        for(auto it:m)
        {
            if(it.second>0)
                return false;
        }
        return true;
    }
};