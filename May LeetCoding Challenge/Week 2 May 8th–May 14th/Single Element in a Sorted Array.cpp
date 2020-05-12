class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        int left=0;
        int right=n-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            int index=mid%2;
            if(index==1)
                if(mid-1>=0 )
                    if(nums[mid]!=nums[mid-1])
                        if(mid+1<n)
                            if(nums[mid]!=nums[mid+1])
                                return nums[mid];
            if(index==0)
                if(mid+1<n)
                    if(nums[mid]!=nums[mid+1])
                        if(mid-1>=0 )
                            if(nums[mid]!=nums[mid-1])
                                return nums[mid];
            if(index==1)
            {
              
                if(nums[mid]==nums[mid-1])
                    left=mid+1;
                else
                    right=mid-1;  
            }
            if(index==0)
            {
                if(nums[mid]==nums[mid+1])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};
