class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        int x=log2(num);
        if(x%2)
            return false;
        int y=1<<x;
        int z=y&num;
        if(z==num)
            return true;
        return false;
    }
};