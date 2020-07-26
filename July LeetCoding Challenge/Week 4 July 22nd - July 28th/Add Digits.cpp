class Solution {
public:
    int addDigits(int num) {
        int n=num;
        int sum=num;
        while(n>=10)
        {
            sum=0;
            while(n)
            {
                sum+=n%10;
                n/=10;
            }
            n=sum;
        }
        return sum;
    }
};
