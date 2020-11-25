class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%5==0 || K%2==0)
            return -1;
        int num=0;
        int i=1;
        while(1)
        {
            num=(num*10+1)%K;
            if(num==0)
                return i;
            i++;
        }
        return -1;
    }
};
