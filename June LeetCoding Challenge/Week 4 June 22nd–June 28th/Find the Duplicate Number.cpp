class Solution {
public:
    int BNARY_SEARCH(vector<int>& nums)
    {
        int count;
        int left=1;
        int right=nums.size();
        int mid;
        while(left<right)
        {
            count=0;
            mid=left+(right-left)/2;
            for(int i:nums)
            {
                if(i<=mid)
                    count++;
            }
            if(count>mid)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
    int findDuplicate(vector<int>& nums) {
        return BNARY_SEARCH(nums);
    }
};
