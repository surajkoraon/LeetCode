class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<pair<char,int>> st;
        int score=0;
        for(char ch:S)
        {
            if(ch=='(')
            {
                st.push({ch,0});
            }
            else
            {
                int temp=st.top().second;
                if(temp==0)
                    temp=1;
                else
                    temp=temp*2;
                st.pop();
                if(!st.empty())
                {
                    int tmp=st.top().second;
                    st.pop();
                    st.push({'(',temp+tmp});
                }
                else
                {
                    score+=temp;
                }
            }
        }
        return score;
    }
};