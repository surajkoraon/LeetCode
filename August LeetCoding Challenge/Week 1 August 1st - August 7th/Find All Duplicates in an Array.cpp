class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size();i++)
            v[nums[i]-1]++;
        int j=0;
        for(int i=0;i<nums.size();i++)
            if(v[i]==2)
                nums[j++]=i+1;
        nums.erase(nums.begin()+j,nums.end());
        return nums;
    }
};
