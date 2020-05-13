class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k)
            return "0";
        if(n==0)
            return "0";
        int start=0;
        int end=0;
        if(n>1)
            end++;
        string sol;
        for(int i=0;i<n;i++)
        {
            int j=sol.size()-1;
            while(sol.size()>0 && sol[j]>num[i] && k-->0)
            {
                sol.erase(sol.begin()+j);
                j=sol.size()-1;
            }
            if(sol.size() || num[i]!='0')
                sol+=num[i];
        }
        while(k-->0)
        {
            sol.erase(sol.size()-1);
        }
        if(sol.size()==0)
            return "0";
        return sol;
    }
};
