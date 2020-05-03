class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0; // XOR with zero is num itself and XOR with itself is zero
        for(int x : nums){
            result ^= x;
        }
        
        return result;
    }
};