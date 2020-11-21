class Solution {
public:
    int sum=0;
    int N;
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string target=to_string(n);
        int size=target.size();
        N=digits.size();
        for(int i=1;i<size;i++)
            sum+=pow(N,i);
        for(int j=0;j<size;j++)
        {
            bool flag=0;
            for(int i=0;i<N;i++)
            {
                if(digits[i][0]<target[j])
                    sum+=pow(N,size-j-1);
                else if(digits[i][0]==target[j])
                    flag=1;
            }
            if(!flag)
                return sum;
        }
        return sum+1;
    }
};
