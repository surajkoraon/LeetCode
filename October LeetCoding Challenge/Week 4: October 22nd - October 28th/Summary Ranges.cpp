class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        if(nums.size()==1)
            return {to_string(nums[0])};
        string const arrow="->";
        vector<int> v;
        int n=nums.size();
        int temp=nums[0];
        v.push_back(temp);
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]-1!=temp)
            {
                v.push_back(temp);
                v.push_back(nums[i]);
            }
            temp=nums[i];
        }
        if(nums[n-1]-1!=temp)
        {
            v.push_back(temp);
            v.push_back(nums[n-1]);
        }
        v.push_back(nums[n-1]);
        vector<string> s;
        for(int i=0;i<v.size();i+=2)
        {
            string str=to_string(v[i]);
            if(v[i]!=v[i+1])
                str+=arrow+to_string(v[i+1]);
            s.push_back(str);
        }
        return s;
    }
};
