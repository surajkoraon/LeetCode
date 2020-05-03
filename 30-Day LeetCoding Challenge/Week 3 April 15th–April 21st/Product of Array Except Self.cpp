class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> before={1};
        for(int i=1;i<nums.size();i++)
        {
            before.push_back(before[i-1]*nums[i-1]);
        }
        list<int> after={1};
        for(int i=(int)nums.size()-2;i>=0;i--) 
        {
            after.push_front(after.front()*nums[i+1]);
        }
        vector<int> ans;
        auto it=after.begin();
        for(int i=0;i<nums.size()&&it!=after.end();i++,it++)
        {
            ans.push_back(before[i]*(*it));
        }
        return ans;
    }
};