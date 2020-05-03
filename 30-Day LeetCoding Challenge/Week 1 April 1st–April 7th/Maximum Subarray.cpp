class Solution {
    
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, max_so_far = 0;
        
        for(int x : nums){
            max_so_far = max(x, max_so_far + x);
            result = max(result, max_so_far);
            
        }
        
        return result;
    }
};