class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        int ans=INT_MAX;
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                int a=INT_MAX,b=INT_MAX;
                if(j<triangle[i].size()-1)
                    a=triangle[i-1][j];
                if(j>0)
                    b=triangle[i-1][j-1];
                triangle[i][j]+=min(a,b);
                if(i==triangle.size()-1)
                    ans=min(ans,triangle[i][j]);
            }
        }
        return ans;
    }
};
