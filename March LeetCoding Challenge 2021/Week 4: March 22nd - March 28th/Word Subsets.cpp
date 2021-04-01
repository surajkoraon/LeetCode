class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26,0);
        vector<string> ans;
        for(string b:B)
        {
            vector<int> temp(26,0);
            for(char ch:b)
            {
                temp[ch-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                count[i]=max(count[i],temp[i]);
            }
        }
        for(string a:A)
        {
            vector<int> temp(26,0);
            for(char ch:a)
            {
                temp[ch-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(temp[i]<count[i])
                {
                    break;
                }
                else if(i==25)
                {
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};
