class Solution {
public:
    stack<int> num;
    stack<char> op;
    int calc(int a,int b,char op)
    {
        switch(op)
        {
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':return a/b;
        }
        return 0;
    }
    void helper()
    {
        int b=num.top();
        num.pop();
        int a=num.top();
        num.pop();
        char operators=op.top();
        op.pop();
        int c=calc(a,b,operators);
        num.push(c);
    }
    int calculate(string s) {
        unordered_map<char,int> m;
        m['+']=0;
        m['-']=1;
        m['/']=2;
        m['*']=2;
        bool flag=false;
        for(char ch:s)
        {
            if(ch==' ')
                continue;
            if(m.count(ch)>0)
            {
                flag=false;
                while(!op.empty() && m[op.top()]>=m[ch])
                    helper();
                op.push(ch);
            }
            else
            {
                int a=ch-'0';
                if(flag)
                {
                    a=num.top()*10+a;
                    num.pop();
                }
                num.push(a);
                flag=true;
            }
        }
        while(!op.empty())
            helper();
        return num.top();
    }
};
