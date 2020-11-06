class Solution {
public:
    int sum(vector<int>& nums,double mid)
    {
        int sum=0;
        for(double x:nums)
            sum+=ceil(x/mid);
        return sum;
    }
    int binarySearch(vector<int>& nums,int key)
    {
        int sol;
        int left=1;
        int right=nums[nums.size()-1];
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            int midSum=sum(nums,mid);
            if(midSum>key)
                left=mid+1;
            else if(midSum<=key)
            {
                right=mid-1;
                sol=mid;
            }
        }
        return sol;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        return binarySearch(nums,threshold);
    }
};
