class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int n:nums)
        {
            m[n]++;
            if(m[n-1]>0 || m[n+1]>0)
                ans=max(ans,m[n]+max(m[n-1],m[n+1]));
        }
        return ans;
    }
};