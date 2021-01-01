class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size();
        stack<int> st;
        int i=0,area=0;
        while (i<n) 
        {
            if (st.empty() || heights[i]>=heights[st.top()]) 
                st.push(i++);
            else 
            {
                int index=st.top();
                st.pop();
                area=max(area,heights[index]*(st.empty()?i:i-st.top()-1));
            }
        }
        return area;
    }
};
