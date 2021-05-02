class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int low=1;
        int high=n;
        bool flag=1;
        vector<int> v;
        for(int i=0;i<k;i++)
        {
            if(flag)
            {
                v.push_back(low);
                low++;
            }
            else
            {
                v.push_back(high);
                high--;
            }
            flag=!flag;
        }
        int start,end;
        if(k&1)
        {
            for(int i=low;i<=high;i++)
            {
                v.push_back(i);
            }
        }
        else
        {
            for(int i=high;i>=low;i--)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};
