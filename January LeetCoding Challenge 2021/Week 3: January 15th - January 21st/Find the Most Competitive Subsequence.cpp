class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> v;
        int n=nums.size();
        v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            while(v.size()>0 && nums[i]<v[v.size()-1] && k-v.size()<n-i)
            {
                v.pop_back();
            }
            if(v.size()<k)
                v.push_back(nums[i]);
        }
        return v;
    }
};
