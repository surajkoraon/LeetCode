class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int a=floor(log2(N))+1;
        a=1<<a;
        return (a-1)^N;
    }
};
