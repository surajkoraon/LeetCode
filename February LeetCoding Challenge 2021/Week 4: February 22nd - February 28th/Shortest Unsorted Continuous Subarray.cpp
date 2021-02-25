class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[n-1];
        int start=n-1,end=0;
        for(int i=1,j=n-2;i<n;i++,j--)
        {
            if(nums[i]<maxi)
            {
                end=i;
            }
            else
            {
                maxi=nums[i];
            }
            if(nums[j]>mini)
            {
                start=j;
            }
            else
            {
                mini=nums[j];
            }
        }
        if(start<end)
            return end-start+1;
        return 0;
    }
};