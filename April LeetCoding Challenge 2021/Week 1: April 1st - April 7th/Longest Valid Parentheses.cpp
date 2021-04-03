class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxLen=0,open=0,close,temp=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
                open++;
            }
            else if(s[i]==')' && open==0)
            {
                st.push(-2);
            }
            else
            {
                close=1;
                while(st.top()!=-1)
                {
                    close+=st.top();
                    st.pop();
                }
                open--;
                st.pop();
                st.push(close);
            }
        }
        while(!st.empty())
        {
            int x=st.top();
            if(x>0)
            {
                temp+=x;
            }
            else
            {
                temp=0;
            }
            maxLen=max(maxLen,temp);
            st.pop();
        }
        return maxLen*2;
    }
};