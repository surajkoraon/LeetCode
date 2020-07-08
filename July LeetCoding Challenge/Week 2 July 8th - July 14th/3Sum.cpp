class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();    
    sort(nums.begin(),nums.end());
    vector<vector<int>> v;
    for (int i=0;i<n;i++) {
        if(nums[i]>0)
            break;
        if ((i>0)&&(nums[i]==nums[i-1]))
            continue;
        int left=i+1;
        int right=n-1;
        while(left<right) 
        {
            int sum=nums[i]+nums[left]+nums[right];
            if(sum>0) 
                right--;
            else if(sum<0)
                left++;
            else 
            {
                v.push_back(vector<int> {nums[i], nums[left], nums[right]});
                while (left<(n-1) && nums[left]==nums[left+1])
                    left++;
                while (right>0 && nums[right]==nums[right-1])
                    right--;
                left++;
                right--;
            }
        }
    }
    return v;
}
};