class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len=0;
        bool is1encountered=false;
        for(int x:nums)
        {
            if(x==1)
            {
                if(is1encountered && len<k)
                    return false;
                len=0;
                is1encountered=true;
            }
            else
            {
                len++;
            }
        }
        return true;
    }
};
