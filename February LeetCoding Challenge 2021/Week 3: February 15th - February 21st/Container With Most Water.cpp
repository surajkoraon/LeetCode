class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxiArea=0;
        int start=0;
        int n=height.size();
        int end=n-1;
        while(start<end)
        {
            int a=height[start];
            int b=height[end];
            int length=min(a,b);
            int area=length*(end-start);
            maxiArea=max(maxiArea,area);
            if(a<b)
                start++;
            else
                end--;
        }
        return maxiArea;
    }
};