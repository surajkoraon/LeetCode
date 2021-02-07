class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string c;
        for(int i=0;i<path.length();i++)
        {
            char ch=path[i];
            if(ch=='/')
            {
                if(c=="..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else if(c!="" && c!=".")
                    st.push(c);
                c="";
            }
            else
                c+=ch;
        }
        if(c=="..")
        {
            if(!st.empty())
                st.pop();
        }
        else if(c!="" && c!=".")
            st.push(c);
        path="";
        while(!st.empty())
        {
            path="/"+st.top()+path;
            st.pop();
        }
        return path==""?"/":path;
    }
};