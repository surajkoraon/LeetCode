class Solution {
public:
    int findComplement(int num) {
        if(num==1 || num==0)
            return !num;
        long x=log2(num)+1;
        x=1<<x;
        x=x-1;
        x=x^num;
        return x;
    }
};
