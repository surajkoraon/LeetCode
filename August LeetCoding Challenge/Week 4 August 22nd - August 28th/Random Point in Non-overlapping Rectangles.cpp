class Solution {
public:
    vector<int> area;
    vector<vector<int>> rectangle;
    int getArea(vector<int> a)
    {
        return (a[2]-a[0]+1)*(a[3]-a[1]+1);
    }
    int i=0;
    Solution(vector<vector<int>>& rects) {
        rectangle=rects;
        int i=0;
        for(vector<int> a:rects)
        {
            int temp=getArea(a);
            if(i!=0)
                temp+=area[i-1];
            area.push_back(temp);
            i++;
        }
    }
    
    vector<int> pick() {
        int temp=rand()%area.back()+1;
        int index=lower_bound(area.begin(),area.end(),temp)-area.begin();
        int x=rand()%(rectangle[index][2]-rectangle[index][0]+1)+rectangle[index][0];
        int y=rand()%(rectangle[index][3]-rectangle[index][1]+1)+rectangle[index][1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */