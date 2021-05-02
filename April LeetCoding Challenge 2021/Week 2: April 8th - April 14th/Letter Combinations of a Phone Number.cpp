class Solution {
public:
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void dfs(string digits,string s,int index)
    {
        if(index==digits.length())
        {
            ans.push_back(s);
            return;
        }
        int len=digits[index]-'0';
        for(int i=0;i<v[len].length();i++)
        {
            dfs(digits,s+v[len][i],index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        dfs(digits,"",0);
        return ans;
    }
};
