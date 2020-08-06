class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32]={0};
        for(int i:nums)
        {
            int n=i;
            for(int j=0;j<32;j++)
            {
                bit[j]+=n&1;
                n=n>>1;
                if(!n)
                    break;
            }
        }
        int res=0;
        for(int i=0;i<32;i++)
        {
            int n=bit[i]%3;
            if(n)
                res+=n<<i;
        }
        return res;
    }
};
