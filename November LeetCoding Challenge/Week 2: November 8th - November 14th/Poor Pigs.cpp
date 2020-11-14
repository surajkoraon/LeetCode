class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n=minutesToTest/minutesToDie;
        int pigs=ceil(log2(buckets)/log2(n+1));
        return pigs;
    }
};
