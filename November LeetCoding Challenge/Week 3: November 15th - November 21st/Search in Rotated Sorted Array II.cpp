class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        if(n==0)
            return false;
        int mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]>nums[high])
            {
              if(nums[mid]>target && nums[low] <= target) 
                  high = mid-1;
              else 
                  low = mid + 1;
            }
            else if(nums[mid] < nums[high])
            {
              if(nums[mid]<target && nums[high] >= target) 
                  low = mid + 1;
              else 
                  high = mid-1;
            }
            else
              high--;
        }
        return nums[low] == target ? true : false;
    }
};
