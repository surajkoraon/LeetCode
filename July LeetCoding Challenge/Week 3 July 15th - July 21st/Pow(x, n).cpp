class Solution {
public:
    double myPow(double x, int n) {
        double sol=1;
        int N=abs(n);
        while(N>0)
        {
            if(N&1)
                sol*=x;
            x*=x;
            N=N>>1;
        }
        return n<0?1/sol:sol;
    }
};