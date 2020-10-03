class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int sol=0;
        unordered_map<int,int> s;
        unordered_map<int,int> m;
        int a,b;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]+k)>0 && m[nums[i]+k]!=i)
            {
                a=nums[i]+k;
                b=nums[i];
                s[a]=b;
            }
        }
        return s.size();
    }
};
