class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i:nums)
        {
            m[i]++;
        }
        for(auto it:m)
        {
            if(it.second==1)
                v.push_back(it.first);
        }
        return v;
    }
};
