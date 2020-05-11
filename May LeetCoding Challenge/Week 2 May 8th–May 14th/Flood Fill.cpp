class Solution {
public:
    void dfs(vector<vector<int>>& v, vector<vector<int>>& image, int x, int y, int newcolor, int color)
    {
        int m=image.size();
        int n=image[0].size();
        if(x<0 || y<0 || x>=m || y>=n || v[x][y]!=color)
            return;
        image[x][y]=newcolor;
        v[x][y]=-1;
        dfs(v, image,x+1,y,newcolor,color);
        dfs(v, image,x-1,y,newcolor,color);
        dfs(v, image,x,y+1,newcolor,color);
        dfs(v, image,x,y-1,newcolor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0 || image[sr][sc]==newColor)
            return image;
        vector<vector<int>> v=image;
        dfs(v, image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};
