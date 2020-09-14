class Solution {
public:
    vector<vector<int>> sol;
    void recurse(vector<int>& nums,vector<int> v,vector<bool> u)
    {
        if(v.size()==nums.size())
        {
            sol.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!u[i])
            {
                v.push_back(nums[i]);
                u[i]=true;
                recurse(nums,v,u);
                v.erase(v.end()-1);
                u[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<bool> u(nums.size(),false);
        recurse(nums,v,u);
        return sol;
    }
};
