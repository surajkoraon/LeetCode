class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int one=INT_MAX,two=INT_MAX;
        for(int num:nums)
            if(num<=one)
                one=num;
            else if(num<=two)
                two=num;
            else
                return true;
        return false;
    }
};
