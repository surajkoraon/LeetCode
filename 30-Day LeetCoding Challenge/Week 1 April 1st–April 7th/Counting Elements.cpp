class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int> m;
        for(int i : arr)
            m[i]=0;
        int c=0;
        for(int i : arr)
            if(m.find(i+1)!=m.end())
                c++;
        return c;
    }
};