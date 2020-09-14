class Solution {
public:
    int dp[100];
    int recurse(vector<int>& nums,int index,int total)
    {
        int sum=0;
        if(index>=nums.size())
            return 0;
        for(int i=index;i<nums.size();i++)
        {
            if(dp[i]==-1)
            {
                total=recurse(nums,i+2,total)+nums[i];
                dp[i]=total;
            }
            else
                total=dp[i];
            sum=max(sum,total);
        }
        return sum;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recurse(nums,0,0);
    }
};
