class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int> a,vector<int> b)
             {
                 if(a[0]==b[0])
                 {
                     return a[1]<b[1];
                 }
                 return a[0]<b[0];
             });
        vector<vector<int>> v(people.size(),vector<int>(2,-1));
        for(int i=0;i<people.size();i++)
        {
            int c=people[i][1];
            for(int j=0;j<people.size();j++)
            {
                if(c==0 && v[j][0]==-1)
                {
                    c=j;
                    break;
                }
                if(v[j][0]==-1 || v[j][0]>=people[i][0])
                    c--;
            }
            v[c]=people[i];
        }
        return v;
    }
};
