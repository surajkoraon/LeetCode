class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> m;
        int count=0;
        for(char c:J)
        {
            m[c]++;
        }
        for(char c:S)
        {
            if(m.find(c)!=m.end())
            {
                count++;
            }
        }
        return count;
    }
};