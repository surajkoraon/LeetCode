class Solution {
public:
    int sum(int index,vector<int>& bit)
    {
        int ans=0;
        for(int i=index;i>0;i-=(i & -i))
        {
            ans+=bit[i];
        }
        return ans;
    }
    void update(int index,vector<int>& bit)
    {
        int n=bit.size();
        for(int i=index;i<=100000;i+=(i & -i))
        {
            bit[i]+=1;
        }
    }
    int createSortedArray(vector<int>& instructions) {
        int n=instructions.size();
        vector<int> bit(100001);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(sum(instructions[i]-1,bit),i-sum(instructions[i],bit));
            ans%=1000000007;
            update(instructions[i],bit);
        }
        return ans;
    }
};
