class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index=nums.size()-1;
        int low=0;
        int high=index;
        vector<int> v(index+1,0);
        while(low<=high)
        {
            if(nums[low]*nums[low]<nums[high]*nums[high])
            {
                v[index]=nums[high]*nums[high];
                high--;
            }
            else
            {
                v[index]=nums[low]*nums[low];
                low++;
            }
            index--;
        }
        return v;
    }
};
