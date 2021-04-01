class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> dp(n,{1,1});
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                dp[i].first=dp[i-1].second+1;
                dp[i].second=dp[i-1].second;
            }
            else if(nums[i]>nums[i-1])
            {
                dp[i].second=dp[i-1].first+1;
                dp[i].first=dp[i-1].first;
            }
            else
            {
                dp[i]=dp[i-1];
            }
        }
        return max(dp[n-1].first,dp[n-1].second);
    }
};
