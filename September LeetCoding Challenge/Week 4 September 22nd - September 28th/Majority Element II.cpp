class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size()/3;
        vector<int> v;
        for(int i:nums)
        {
            m[i]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>n)
                v.push_back(it->first);
        }
        return v;
    }
};