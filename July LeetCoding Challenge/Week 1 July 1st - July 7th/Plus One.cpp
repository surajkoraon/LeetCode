class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus=1;
        int x=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--)
        {
            plus=(digits[i]+plus)/10;
            digits[i]=(digits[i]+x)%10;
            x=plus;
        }
        if(plus)
        {
            digits.insert(digits.begin(),plus);
        }
        return digits;
    }
};
