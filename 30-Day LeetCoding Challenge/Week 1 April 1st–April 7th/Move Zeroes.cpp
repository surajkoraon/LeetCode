class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count_zeros  = 0;
        
        int n = nums.size();
        
        for(int index = 0; index < n; index++){
            if(nums[index] != 0){
                nums[count_zeros++] = nums[index];
            }
        }
        
        for(int index=count_zeros; index < n; index++){
            nums[index] = 0;
        }
    }
};