class Solution {
public:
    int available=0;
    void helper(int start,int end,int n)
    {
        int place=end-start-1;
        if(start==-1 && end==n)
            place=ceil((float)place/2);
        else if(start!=-1 && end!=n)
            place=(place-1)/2;
        else
            place=ceil((float)(place-1)/2);
        available+=place;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int start=-1;
        int end=0;
        int size=flowerbed.size();
        for(int i=0;i<size;i++)
        {
            int x=flowerbed[i];
            if(x==0)
                end++;
            else
            {
                helper(start,end,size);
                start=i;
                end=i+1;
            }
        }
        helper(start,end,size);
        return available>=n;
    }
};
