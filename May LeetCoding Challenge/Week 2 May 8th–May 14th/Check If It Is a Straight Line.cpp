class Solution {
public:
    int crossProduct(int x1,int y1,int x2,int y2)
    {
        return x1*y2-x2*y1;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==2)
            return true;
        int x=coordinates[0][0];
        int y=coordinates[0][1];
        int x2=coordinates[n-1][0]-x;
        int y2=coordinates[n-1][1]-y;
        for(int i=1;i<n-1;i++)
        {
            int x1=coordinates[i][0]-x;
            int y1=coordinates[i][1]-y;
            if(crossProduct(x1,y1,x2,y2)!=0)
                return false;
        }
        return true;
    }
};