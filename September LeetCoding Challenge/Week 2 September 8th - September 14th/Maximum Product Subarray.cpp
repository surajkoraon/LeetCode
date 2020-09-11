class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxsofar=INT_MIN;
        int neg=1;
        int pos=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(neg,pos);
            pos=max(pos*nums[i],nums[i]);
            neg=min(neg*nums[i],nums[i]);
            maxsofar=max(maxsofar,pos);
        }
        return maxsofar;
    }
};
