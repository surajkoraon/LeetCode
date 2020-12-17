class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int len=1;len<=n;len++)
        {
            for(int left=1;left<=n-len+1;left++)
            {
                int right=left+len-1;
                for(int j=left;j<=right;j++)
                {
                    dp[left][right]=max(dp[left][right],
                    nums[left-1]*nums[j]*nums[right+1]+
                    dp[left][j-1]+dp[j+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
