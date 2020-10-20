class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        auto startit=nums.begin(),endit=nums.end();
        reverse(startit,endit-k);
        reverse(endit-k,endit);
        reverse(startit,endit);
    }
};