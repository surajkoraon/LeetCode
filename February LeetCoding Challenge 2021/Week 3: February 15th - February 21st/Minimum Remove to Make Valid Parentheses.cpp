class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> stk;
        int n=s.length();
        vector<bool> arr(n,true);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push({'(',i});
            }
            else if(s[i]==')')
            {
                if(stk.empty())
                {
                    arr[i]=false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        while(!stk.empty())
        {
            arr[stk.top().second]=false;
            stk.pop();
        }
        string str;
        for(int i=0;i<n;i++)
        {
            if(arr[i])
            {
                str+=s[i];
            }
        }
        return str;
    }
};