class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0)
            return 0;
        int step=1;
        while(num)
        {
            if(num&(num-1)==0)
            {
                return step+log2(num);
            }
            if(num&1)
            {
                num--;
            }
            else
            {
                num/=2;
            }
            step++;
        }
        return step;
    }
};