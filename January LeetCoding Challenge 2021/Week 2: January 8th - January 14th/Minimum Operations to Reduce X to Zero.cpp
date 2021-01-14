class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        int n=nums.size();
        for(int i : nums) 
            target+=i;
        if(target==0) 
            return n;
        if(target<0) 
            return -1;
        int res=-1,sum=0,left=0;
        for(int i=0;i<n;i++) 
        {
            sum+=nums[i];
            while(sum>target)
                sum-=nums[left++];
            if(sum==target)
                res=max(res,i-left+1);
        }
        
        return res==-1?-1:n-res;
    }
};
