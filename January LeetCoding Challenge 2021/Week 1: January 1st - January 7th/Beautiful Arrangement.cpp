class Solution {
public:
    int count=0;
    int N;
    void recurse(vector<int>& v,vector<bool>& visited,int index)
    {
        if(N==v.size())
        {
            count++;
            cout<<endl;
            return;
        }
        for(int i=1;i<=N;i++)
        {
            if(!visited[i] && (i%index==0 || index%i==0))
            {
                v.push_back(i);
                visited[i]=true;
                recurse(v,visited,index+1);
                v.pop_back();
                visited[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v;
        vector<bool> visited(16,false);
        N=n;
        recurse(v,visited,1);
        return count;
    }
};
