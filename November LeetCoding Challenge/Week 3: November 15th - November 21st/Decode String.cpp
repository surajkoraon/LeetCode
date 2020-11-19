class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<char> ch;
        int count=0;
        for(char c:s)
        {
            if(c>='0' && c<='9')
            {
                count=count*10+(c-'0');;
            }
            else if(c==']')
            {
                int size=num.top();
                num.pop();
                string tmp;
                while(ch.top()!='[')
                {
                    tmp=ch.top()+tmp;
                    ch.pop();
                }
                ch.pop();
                string t;
                for(int i=0;i<size;i++)
                {
                    t+=tmp;
                }
                for(char x:t)
                {
                    ch.push(x);
                }
            }
            else
            {
                if(c=='[')
                {
                    num.push(count);
                    count=0;
                }
                ch.push(c);
            }
        }
        string sol;
        while(!ch.empty())
        {
            sol=ch.top()+sol;
            ch.pop();
        }
        return sol;
    }
};
