class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
        if(!n)
            return n;
        return !(n & (n-1));
    }
};