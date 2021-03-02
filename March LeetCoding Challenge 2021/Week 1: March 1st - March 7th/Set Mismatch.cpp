class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<bool> v(n+1,false);
        int a,b,sum=0;
        for(int x:nums)
        {
            if(!v[x])
            {
                v[x]=true;
            }
            else
            {
                a=x;
            }
            sum+=x;
        }
        n=n*(n+1)/2;
        b=n-sum+a;
        return {a,b};
    }
};
