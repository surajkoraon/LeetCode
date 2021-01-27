class Solution {
public:
    long long recurse(long long n)
    {
        if(n==1)
            return 1;
        return (n|((recurse(n-1)%1000000007)<<((int)log2(n)+1)))%1000000007;
    }
    int concatenatedBinary(int n) {
        return recurse(n);
    }
}; 
