class Solution {
public:
    vector<int> a;
    void generate(int N,int K,int digit,int n,int num)
    {
        if(digit<0 || digit>9)
            return;
        num+=digit*pow(10,n);
        if(n==0)
        {
            a.push_back(num);
            return;
        }
        generate(N,K,digit-K,n-1,num);
        if(K>0)
        {
            generate(N,K,digit+K,n-1,num);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        int start=(N==1)?0:1;
        for(int i=start;i<=9;i++)
        {
            generate(N,K,i,N-1,0);    
        }
        return a;
    }
};
