class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b)
             {
                 string x=to_string(a);
                 string y=to_string(b);
                 return x+y>y+x;
             });
        string s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.length()==1 && s[s.length()-1]=='0' && nums[i]==0);
            else
                s+=to_string(nums[i]);
            
        }
        return s;
    }
};
