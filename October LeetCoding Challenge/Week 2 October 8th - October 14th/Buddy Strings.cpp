class Solution {
public:
    bool buddyStrings(string A, string B) {
        int m=A.length(),n=B.length();
        if(m!=n || m<=1 || n<=1)
            return false;
        int alpha[26]={0};
        int sum=0,diff=0;
        bool flag=false;
        for(int i=0;i<m;i++)
        {
            if(!flag && ++alpha[A[i]-'a']>=2)
                flag=true;
            sum+=(A[i]-'a');
            sum-=(B[i]-'a');
            if(A[i]!=B[i])
                diff++;
        }
        return ((sum==0 && diff==2) || (flag && A==B));
    }
};
