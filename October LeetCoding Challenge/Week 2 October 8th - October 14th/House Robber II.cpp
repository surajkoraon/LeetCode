class Solution {
public:
    int dp[100];
    int recurse(vector<int>& v,int index,int end)
    {
        if(index>=end)
            return 0;
        for(int i=index;i<end;i++)
        {
            if(dp[i]==-1)
                dp[i]=recurse(v,i+2,end)+v[i];
            dp[index]=max(dp[index],dp[i]);
        }
        return dp[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        memset(dp,-1,sizeof(dp));
        int a=recurse(nums,1,nums.size());
        memset(dp,-1,sizeof(dp));
        int b=recurse(nums,0,nums.size()-1);
        return max(a,b);
    }
};
