class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=0;i<order.length();i++)
        {
            m[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(j==words[i+1].length())
                    return false;
                if(m[words[i][j]]<m[words[i+1][j]])
                {
                    break;
                }
                else if(m[words[i][j]]>m[words[i+1][j]])
                {
                    return false;
                }
                
            }
        }
        return true;
    }
};
