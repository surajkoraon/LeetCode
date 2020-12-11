class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int limit=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                if(++limit>2)
                {
                    auto it=nums.begin()+i;
                    nums.erase(it);
                    i--;
                }
            }
            else
                limit=1;
        }
        return nums.size();
    }
};
