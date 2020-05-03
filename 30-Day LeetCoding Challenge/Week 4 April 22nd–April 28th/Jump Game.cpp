class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        vector<int> index;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==0 && i<nums.size()-1)
            {
                index.push_back(i);
            }
        }
        int count=0;
        int start=0;
        for(int i=0;i<index.size();i++)
        {
            for(int j=start;j<index[i];j++)
            {
                if(nums[j]>(index[i]-j))
                {
                    count++;
                    break;
                }
            }
        }
        if(count==index.size())
            return true;
        return false;
    }
};