class Solution {
public:
    int overlap=0;
    int maxOverlap(vector<pair<int,int>> &v,vector<vector<int>>& B,int x,int y)
    {
        int size=B.size(); 
        int count=0;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            int a=v[i].first;
            int b=v[i].second;
            if(x+a<size && x+a>=0 && y+b<size && y+b>=0)
            {
                if(B[x+a][y+b]==1)
                    count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int,int>> v,u;
        bool flag=0;
        int x,y;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
            {
                if(!flag && A[i][j]==1)
                {
                    x=i;
                    y=j;
                    pair<int,int> p={0,0};
                    v.push_back(p);
                    flag=1;
                }
                else if(flag && A[i][j]==1)
                {
                    pair<int,int> p={i-x,j-y};
                    v.push_back(p);
                }
            }
        }
        flag=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
            {
                if(!flag && B[i][j]==1)
                {
                    x=i;
                    y=j;
                    pair<int,int> p={0,0};
                    u.push_back(p);
                    flag=1;
                }
                else if(flag && B[i][j]==1)
                {
                    pair<int,int> p={i-x,j-y};
                    u.push_back(p);
                }
            }
        }
        int count=0;
        for(int i=0;i<B.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                overlap=max(overlap,maxOverlap(v,B,i,j));
                overlap=max(overlap,maxOverlap(u,A,i,j));
            }
        }
        return overlap;
    }
};
