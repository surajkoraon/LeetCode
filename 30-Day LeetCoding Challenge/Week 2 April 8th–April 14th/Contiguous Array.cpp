class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> m;
        int arr[nums.size()];
        int count=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count+=-1;
            else
                count+=1;
            if(count==0)
            {
                maxlen=i+1;
                continue;
            }
            if(m.find(count)==m.end())
                m[count]=i;
            else
            {
                maxlen=max(maxlen,i-m[count]);
            }
        }
        return maxlen;
    }
};